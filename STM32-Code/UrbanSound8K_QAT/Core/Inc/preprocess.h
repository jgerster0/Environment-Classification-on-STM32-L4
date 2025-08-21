#ifndef PREPROCESS_H
#define PREPROCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../Drivers/CMSIS/DSP/Include/arm_math.h"
#include "../../Drivers/CMSIS/DSP/Include/dsp/transform_functions.h"

// Constants for audio processing
#define FRAME_SIZE 1024
#define FRAME_STEP 512
#define NUM_MFCC 16

// Function declarations (fixed!)
void init_mfcc(void);
void process_mfcc(const float32_t *RecBuff, int buffer_size, float32_t *mfcc_out);
void compute_single_mfcc_frame(const float32_t *frame_data, float32_t *output_mfcc);


#ifdef __cplusplus
}
#endif

#endif
