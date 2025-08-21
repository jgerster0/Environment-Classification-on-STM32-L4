/*
 * app.h
 *
 *  Created on: Mar 23, 2023
 *      Author: Viviane Potocnik <vivianep@iis.ee.ethz.ch>
 */
#include <stdint.h>

#ifndef INC_APP_H_
#define INC_APP_H_

#ifdef __cplusplus
extern "C" {
#endif

void tflm_init();
float* application(float *mfcc_buffer);

//int application(uint8_t *mfcc_buffer);
void DebugLog(const char* s);


#ifdef __cplusplus
}
#endif

#endif /* INC_APP_H_ */
