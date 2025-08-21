/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_x-cube-ai.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "ai_datatypes_defines.h"
#include "ai_platform.h"

#include <stdio.h>
#include "preprocess.h"

#include "mfcc_input.h"
#include "app.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define FFT_SIZE 1024
#define FRAME_STEP 512
#define NUM_MFCC 16
#define NUM_FRAMES 30
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
float32_t audio_float_buffer[FFT_SIZE];
float32_t mfcc_out[NUM_MFCC]; // single frame MFCC output
float mfcc_feature_buffer[NUM_FRAMES * NUM_MFCC];  // Stores 30 frames of MFCCs

#define AUDIO_WINDOW_SIZE (FFT_SIZE)
float audio_window[AUDIO_WINDOW_SIZE];


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void DWT_Init(void)
{
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
  DWT->CYCCNT = 0;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

	  HAL_Init();
	  SystemClock_Config();
	  MX_GPIO_Init();
	  MX_X_CUBE_AI_Init();
	  init_mfcc();
	  DWT_Init();

  ai_error ai_err;
  ai_i32 nbatch;


	static bool mfcc_initialized = false;

	static bool full = false;

	float32_t confidence;

	// if true, mode is tflite, if false mode is cubeai
	static bool tfLite_mode = true;



	AI_ALIGNED(4)
	  ai_u8 activations[AI_PQAT_MODEL_DATA_ACTIVATIONS_SIZE];

	  AI_ALIGNED(4)
	  ai_i8 in_data[AI_PQAT_MODEL_IN_1_SIZE_BYTES];
	  AI_ALIGNED(4)
	  ai_i8 out_data[AI_PQAT_MODEL_OUT_1_SIZE_BYTES];

	  ai_handle pqat_model = AI_HANDLE_NULL;

	  ai_buffer *ai_input;
	  ai_buffer *ai_output;

	  ai_network_params params = {
	    AI_PQAT_MODEL_DATA_WEIGHTS(ai_pqat_model_data_weights_get()),
	    AI_PQAT_MODEL_DATA_ACTIVATIONS(activations)
	  };

	  ai_err = ai_pqat_model_create(&pqat_model, AI_PQAT_MODEL_DATA_CONFIG);
	  if (ai_err.type != AI_ERROR_NONE) {
	    //printf("AI ERROR: ai_pqat_model_create\n");
	    return -1;
	  }

	  if (!ai_pqat_model_init(pqat_model, &params)) {
	      ai_err = ai_pqat_model_get_error(pqat_model);
	      //printf("AI ERROR: ai_pqat_model_init type=%d code=%d\r\n", ai_err.type, ai_err.code);
	      return -1;
	  }

	  ai_input = ai_pqat_model_inputs_get(pqat_model, NULL);
	  ai_output = ai_pqat_model_outputs_get(pqat_model, NULL);

	  ai_input[0].data = AI_HANDLE_PTR(in_data);
	  ai_output[0].data = AI_HANDLE_PTR(out_data);

	  float32_t uart_buffer[1024];
	  printf("Waiting \n");

  while (1)
  {
    /* USER CODE END WHILE */

  //MX_X_CUBE_AI_Process();
    /* USER CODE BEGIN 3 */

    // Read input data from UART buffer

    HAL_UART_Receive(&huart1, (uint8_t*)uart_buffer, 1024 * sizeof(float32_t), HAL_MAX_DELAY);

    //printf("Received \n");


    //MFCC Preprocessing
    uint32_t start = DWT->CYCCNT;

    for (int j = 0; j < 2; j++) {

        if (!mfcc_initialized) {

        	memcpy(audio_window, &uart_buffer, AUDIO_WINDOW_SIZE * sizeof(float32_t));


        } else {

        	memcpy(&audio_window[AUDIO_WINDOW_SIZE - FRAME_STEP], &uart_buffer[j*FRAME_STEP], FRAME_STEP * sizeof(float32_t));

        }

        float32_t frame_data[FFT_SIZE];
        memcpy(frame_data, audio_window, FFT_SIZE * sizeof(float32_t));

        memmove(mfcc_feature_buffer,
                mfcc_feature_buffer + NUM_MFCC,
                (NUM_FRAMES - 1) * NUM_MFCC * sizeof(float32_t));

        compute_single_mfcc_frame(frame_data, &mfcc_feature_buffer[(NUM_FRAMES - 1) * NUM_MFCC]);


        memmove(audio_window, audio_window + FRAME_STEP, (AUDIO_WINDOW_SIZE - FRAME_STEP) * sizeof(float32_t));

        if (!mfcc_initialized){
        	mfcc_initialized = true;
        	break;
        }
    }

   	uint32_t end = DWT->CYCCNT;
   	uint32_t cycles = end - start;




// buffer full, start model inference
    if (mfcc_feature_buffer[0]) {

        full = true;
        int8_t* input_data = (int8_t *)(ai_input[0].data);
        int8_t *output_data = (int8_t *)(ai_output[0].data);


        for (int i = 0; i < AI_PQAT_MODEL_IN_1_SIZE; i++) {
            float val = mfcc_feature_buffer[i];
            int q = (int)roundf(val / 0.8295905f + 83);
            if (q > 127) q = 127;
            if (q < -128) q = -128;
            input_data[i] = (int8_t)q;
        }

        //mode: tflite
        if (tfLite_mode){

        DWT->CYCCNT = 0;

        float* prediction = application(mfcc_feature_buffer);
        uint32_t elapsed = DWT->CYCCNT;
        confidence = prediction[1];

        //send output data via uart
        printf("%d %.2f %u\r\n", (int)prediction[0], prediction[1], elapsed);
        }

        //mode: cubeai
        else{
        DWT->CYCCNT = 0;
        nbatch = ai_pqat_model_run(pqat_model, ai_input, ai_output);
        uint32_t elapsed = DWT->CYCCNT;



        ai_u8 *raw_out = (ai_u8*)(ai_output[0].data);
        int8_t output_data1[AI_PQAT_MODEL_OUT_1_SIZE_BYTES];
        for (int i = 0; i < AI_PQAT_MODEL_OUT_1_SIZE_BYTES; i++) {
          output_data1[i] = (int8_t)raw_out[i];
        }
        // Find predicted class
        float32_t max_value = (output_data1[0] - (-128)) * 0.00390625f;  // dequantize
        int predicted_class = 0;

        for (int i = 1; i < 10; i++) {
            float32_t val = (output_data1[i] - (-128)) * 0.00390625f;  // dequantize
            if (val > max_value) {
                max_value = val;
                predicted_class = i;
            }
        }

        confidence = max_value;

        //send output data via uart
        printf("%d %.2f %u\r\n", predicted_class, confidence, elapsed);

        }

        //blink leds
        if (confidence < 0.8f) {
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
        } else {
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
        }


        continue;
      }
    	// send data when filling first frames
        printf("ack %lu %d \r\n", cycles, tfLite_mode);

        continue;

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Enable GPIOA clock */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /* Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // Set PA5 low (LED OFF initially)

  /* Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;   // Push-Pull mode
  GPIO_InitStruct.Pull = GPIO_NOPULL;            // No pull-up or pull-down
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;   // Speed can be LOW for LED
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);





  /* Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET); // Set PA5 low (LED OFF initially)

  /* Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;   // Push-Pull mode
  GPIO_InitStruct.Pull = GPIO_NOPULL;            // No pull-up or pull-down
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;   // Speed can be LOW for LED
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
