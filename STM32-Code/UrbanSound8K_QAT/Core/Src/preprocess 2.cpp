#include "preprocess.h"
#include "mfcc_params.h"
#include "../../Drivers/CMSIS/DSP/Include/dsp/transform_functions.h"  // CMSIS-DSP MFCC



arm_mfcc_instance_f32 mfcc;
// Temporary buffer for arm_mfcc_f32
static float32_t mfcc_tmp_buffer[FFT_SIZE + 2];


void init_mfcc(void){
    arm_mfcc_init_f32(
        &mfcc,
        FFT_SIZE,
        NUM_MEL_BINS,
        NUM_MFCC,
        dct_matrix,
        filter_positions,
        filter_lengths,
        mel_filters,
        hamming_window
    );
}




void process_mfcc(const float32_t *RecBuff, int buffer_size, float32_t *mfcc_out){
    int num_frames = (buffer_size - FFT_SIZE) / FRAME_STEP + 1;

    for(int i = 0; i < num_frames; i++){
        const float32_t *frame_ptr = &RecBuff[i * FRAME_STEP];

        arm_mfcc_f32(
            &mfcc,
            (float32_t*)frame_ptr,
            &mfcc_out[i * NUM_MFCC],
            mfcc_tmp_buffer
        );
    }
}



void compute_single_mfcc_frame(const float32_t *frame_data, float32_t *output_mfcc) {
    arm_mfcc_f32(
        &mfcc,
        (float32_t*)frame_data,
        output_mfcc,
        mfcc_tmp_buffer
    );
}
