################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/app.cpp \
../Core/Src/preprocess.cpp 

C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32l4xx_hal_msp.c \
../Core/Src/stm32l4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32l4xx.c 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32l4xx_hal_msp.d \
./Core/Src/stm32l4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32l4xx.d 

OBJS += \
./Core/Src/app.o \
./Core/Src/main.o \
./Core/Src/preprocess.o \
./Core/Src/stm32l4xx_hal_msp.o \
./Core/Src/stm32l4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32l4xx.o 

CPP_DEPS += \
./Core/Src/app.d \
./Core/Src/preprocess.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -DCMSIS_NN -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/schema" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/kernels" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro/memory_planner" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/ruy" -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/schema" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/kernels" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro/memory_planner" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/ruy" -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/app.cyclo ./Core/Src/app.d ./Core/Src/app.o ./Core/Src/app.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/preprocess.cyclo ./Core/Src/preprocess.d ./Core/Src/preprocess.o ./Core/Src/preprocess.su ./Core/Src/stm32l4xx_hal_msp.cyclo ./Core/Src/stm32l4xx_hal_msp.d ./Core/Src/stm32l4xx_hal_msp.o ./Core/Src/stm32l4xx_hal_msp.su ./Core/Src/stm32l4xx_it.cyclo ./Core/Src/stm32l4xx_it.d ./Core/Src/stm32l4xx_it.o ./Core/Src/stm32l4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/system_stm32l4xx.cyclo ./Core/Src/system_stm32l4xx.d ./Core/Src/system_stm32l4xx.o ./Core/Src/system_stm32l4xx.su

.PHONY: clean-Core-2f-Src

