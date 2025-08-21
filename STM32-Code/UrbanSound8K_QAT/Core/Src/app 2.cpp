#include "app.h"
#include <stdint.h>

extern "C" {
    #include "main.h"
}



#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_allocator.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "final_qat.h"
#include <cmath>


// globals
tflite::ErrorReporter* error_reporter = nullptr;
const tflite::Model* nn = nullptr;
tflite::MicroInterpreter* interpreter = nullptr;
TfLiteTensor* nn_input = nullptr;
TfLiteTensor* nn_output = nullptr;
constexpr size_t kTensorArenaSize = 40*1024;

uint8_t tensor_arena[kTensorArenaSize];




uint32_t num_elements;
uint32_t num_output_elements;
int8_t y_val_0;
int8_t y_val_1;
int8_t y_val_2;
int8_t y_val_3;
int8_t y_val_4;

bool quant = true;

static float arr[2];


//tflite::MicroInterpreter *interpreter = nullptr;
TfLiteTensor          *model_input;
TfLiteTensor          *model_output;
bool                   tf_initialized = false;

// initialize tflite model
void tflm_init() {
  //Target and error reporter
  tflite::InitializeTarget();
  static tflite::MicroErrorReporter micro_error_reporter;
  error_reporter = &micro_error_reporter;

  //Load model
  const tflite::Model *nn = tflite::GetModel(final_qat);
  if (nn->version() != TFLITE_SCHEMA_VERSION) {
    error_reporter->Report("Model schema mismatch");
    return;
  }

  //Ops resolver & arena
  static tflite::AllOpsResolver resolver;
  static uint8_t tensor_arena[kTensorArenaSize];
  static tflite::MicroAllocator *allocator =
    tflite::MicroAllocator::Create(tensor_arena, kTensorArenaSize, error_reporter);

  //Interpreter
  static tflite::MicroInterpreter static_interpreter(
    nn, resolver, allocator, error_reporter);
  interpreter   = &static_interpreter;

  //Allocate memory
  if (interpreter->AllocateTensors() != kTfLiteOk) {
    error_reporter->Report("AllocateTensors failed");
    return;
  }

  // pointers
  model_input   = interpreter->input(0);
  model_output  = interpreter->output(0);

  tf_initialized = true;
}



float* application(float *mfcc_buffer) {
  if (!tf_initialized) {
    tflm_init();
    if (!tf_initialized) return nullptr;
  }

  if (model_input->type == kTfLiteFloat32) {
    for (int i = 0; i < NUM_FRAMES*NUM_MFCC; i++)
      model_input->data.f[i] = mfcc_buffer[i];
  }



  if (model_input->type == kTfLiteInt8) {
   	      for (int i = 0; i < NUM_FRAMES * NUM_MFCC; i++) {
   	    	float val = mfcc_buffer[i];
   	    	int q = (int)roundf(val / model_input->params.scale + model_input->params.zero_point);
   	    	if (q > 127) q = 127;
   	    	if (q < -128) q = -128;
   	    	model_input->data.int8[i] = (int8_t)q;
   	      }
  }



  if (interpreter->Invoke() != kTfLiteOk) {
    error_reporter->Report("Invoke failed");
    return nullptr;
  }


  static float out_arr[2];
  float max_val = -1e9f;
  int   max_idx = 0;


  if (model_output->type == kTfLiteFloat32) {
    float *out = model_output->data.f;
    for (int i = 0; i < 10; i++) {
      if (out[i] > max_val) {
        max_val = out[i];
        max_idx = i;
      }
    }
  }


  if (model_output->type ==  kTfLiteInt8) {

	int8_t* out = model_output->data.int8;
	for (int i = 0; i < 10; i++) {
	    float val = (out[i] - model_output->params.zero_point) * model_output->params.scale;
	    if (val > max_val) {
	        max_val = val;
	        max_idx = i;
	    }
	}
  }


  out_arr[0] = (float)max_idx;
  out_arr[1] = max_val;


  return out_arr;
}





void DebugLog(const char* s)
{
//	return;
	//HAL_UART_Transmit(&huart1, (uint8_t*)s, strlen(s), 100);
}
