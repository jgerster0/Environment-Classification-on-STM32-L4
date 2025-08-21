################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lite/micro/memory_planner/greedy_memory_planner.cc \
../lite/micro/memory_planner/linear_memory_planner.cc \
../lite/micro/memory_planner/non_persistent_buffer_planner_shim.cc 

CC_DEPS += \
./lite/micro/memory_planner/greedy_memory_planner.d \
./lite/micro/memory_planner/linear_memory_planner.d \
./lite/micro/memory_planner/non_persistent_buffer_planner_shim.d 

OBJS += \
./lite/micro/memory_planner/greedy_memory_planner.o \
./lite/micro/memory_planner/linear_memory_planner.o \
./lite/micro/memory_planner/non_persistent_buffer_planner_shim.o 


# Each subdirectory must supply rules for building sources it contributes
lite/micro/memory_planner/%.o lite/micro/memory_planner/%.su lite/micro/memory_planner/%.cyclo: ../lite/micro/memory_planner/%.cc lite/micro/memory_planner/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/ruy" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lite-2f-micro-2f-memory_planner

clean-lite-2f-micro-2f-memory_planner:
	-$(RM) ./lite/micro/memory_planner/greedy_memory_planner.cyclo ./lite/micro/memory_planner/greedy_memory_planner.d ./lite/micro/memory_planner/greedy_memory_planner.o ./lite/micro/memory_planner/greedy_memory_planner.su ./lite/micro/memory_planner/linear_memory_planner.cyclo ./lite/micro/memory_planner/linear_memory_planner.d ./lite/micro/memory_planner/linear_memory_planner.o ./lite/micro/memory_planner/linear_memory_planner.su ./lite/micro/memory_planner/non_persistent_buffer_planner_shim.cyclo ./lite/micro/memory_planner/non_persistent_buffer_planner_shim.d ./lite/micro/memory_planner/non_persistent_buffer_planner_shim.o ./lite/micro/memory_planner/non_persistent_buffer_planner_shim.su

.PHONY: clean-lite-2f-micro-2f-memory_planner

