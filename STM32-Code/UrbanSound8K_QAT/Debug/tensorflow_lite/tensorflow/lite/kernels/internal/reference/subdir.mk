################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../tensorflow_lite/tensorflow/lite/kernels/internal/reference/portable_tensor_utils.cc 

CC_DEPS += \
./tensorflow_lite/tensorflow/lite/kernels/internal/reference/portable_tensor_utils.d 

OBJS += \
./tensorflow_lite/tensorflow/lite/kernels/internal/reference/portable_tensor_utils.o 


# Each subdirectory must supply rules for building sources it contributes
tensorflow_lite/tensorflow/lite/kernels/internal/reference/%.o tensorflow_lite/tensorflow/lite/kernels/internal/reference/%.su tensorflow_lite/tensorflow/lite/kernels/internal/reference/%.cyclo: ../tensorflow_lite/tensorflow/lite/kernels/internal/reference/%.cc tensorflow_lite/tensorflow/lite/kernels/internal/reference/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -DCMSIS_NN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/schema" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/kernels" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro/memory_planner" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/ruy" -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-kernels-2f-internal-2f-reference

clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-kernels-2f-internal-2f-reference:
	-$(RM) ./tensorflow_lite/tensorflow/lite/kernels/internal/reference/portable_tensor_utils.cyclo ./tensorflow_lite/tensorflow/lite/kernels/internal/reference/portable_tensor_utils.d ./tensorflow_lite/tensorflow/lite/kernels/internal/reference/portable_tensor_utils.o ./tensorflow_lite/tensorflow/lite/kernels/internal/reference/portable_tensor_utils.su

.PHONY: clean-tensorflow_lite-2f-tensorflow-2f-lite-2f-kernels-2f-internal-2f-reference

