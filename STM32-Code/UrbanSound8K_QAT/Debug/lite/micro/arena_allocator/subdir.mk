################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.cc \
../lite/micro/arena_allocator/persistent_arena_buffer_allocator.cc \
../lite/micro/arena_allocator/recording_single_arena_buffer_allocator.cc \
../lite/micro/arena_allocator/single_arena_buffer_allocator.cc 

CC_DEPS += \
./lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.d \
./lite/micro/arena_allocator/persistent_arena_buffer_allocator.d \
./lite/micro/arena_allocator/recording_single_arena_buffer_allocator.d \
./lite/micro/arena_allocator/single_arena_buffer_allocator.d 

OBJS += \
./lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.o \
./lite/micro/arena_allocator/persistent_arena_buffer_allocator.o \
./lite/micro/arena_allocator/recording_single_arena_buffer_allocator.o \
./lite/micro/arena_allocator/single_arena_buffer_allocator.o 


# Each subdirectory must supply rules for building sources it contributes
lite/micro/arena_allocator/%.o lite/micro/arena_allocator/%.su lite/micro/arena_allocator/%.cyclo: ../lite/micro/arena_allocator/%.cc lite/micro/arena_allocator/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/ruy" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lite-2f-micro-2f-arena_allocator

clean-lite-2f-micro-2f-arena_allocator:
	-$(RM) ./lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.cyclo ./lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.d ./lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.o ./lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.su ./lite/micro/arena_allocator/persistent_arena_buffer_allocator.cyclo ./lite/micro/arena_allocator/persistent_arena_buffer_allocator.d ./lite/micro/arena_allocator/persistent_arena_buffer_allocator.o ./lite/micro/arena_allocator/persistent_arena_buffer_allocator.su ./lite/micro/arena_allocator/recording_single_arena_buffer_allocator.cyclo ./lite/micro/arena_allocator/recording_single_arena_buffer_allocator.d ./lite/micro/arena_allocator/recording_single_arena_buffer_allocator.o ./lite/micro/arena_allocator/recording_single_arena_buffer_allocator.su ./lite/micro/arena_allocator/single_arena_buffer_allocator.cyclo ./lite/micro/arena_allocator/single_arena_buffer_allocator.d ./lite/micro/arena_allocator/single_arena_buffer_allocator.o ./lite/micro/arena_allocator/single_arena_buffer_allocator.su

.PHONY: clean-lite-2f-micro-2f-arena_allocator

