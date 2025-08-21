################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../lite/micro/all_ops_resolver.cc \
../lite/micro/fake_micro_context.cc \
../lite/micro/flatbuffer_utils.cc \
../lite/micro/memory_helpers.cc \
../lite/micro/micro_allocation_info.cc \
../lite/micro/micro_allocator.cc \
../lite/micro/micro_context.cc \
../lite/micro/micro_error_reporter.cc \
../lite/micro/micro_graph.cc \
../lite/micro/micro_interpreter.cc \
../lite/micro/micro_profiler.cc \
../lite/micro/micro_resource_variable.cc \
../lite/micro/micro_string.cc \
../lite/micro/micro_time.cc \
../lite/micro/micro_utils.cc \
../lite/micro/mock_micro_graph.cc \
../lite/micro/recording_micro_allocator.cc \
../lite/micro/system_setup.cc \
../lite/micro/test_helper_custom_ops.cc \
../lite/micro/test_helpers.cc 

CC_DEPS += \
./lite/micro/all_ops_resolver.d \
./lite/micro/fake_micro_context.d \
./lite/micro/flatbuffer_utils.d \
./lite/micro/memory_helpers.d \
./lite/micro/micro_allocation_info.d \
./lite/micro/micro_allocator.d \
./lite/micro/micro_context.d \
./lite/micro/micro_error_reporter.d \
./lite/micro/micro_graph.d \
./lite/micro/micro_interpreter.d \
./lite/micro/micro_profiler.d \
./lite/micro/micro_resource_variable.d \
./lite/micro/micro_string.d \
./lite/micro/micro_time.d \
./lite/micro/micro_utils.d \
./lite/micro/mock_micro_graph.d \
./lite/micro/recording_micro_allocator.d \
./lite/micro/system_setup.d \
./lite/micro/test_helper_custom_ops.d \
./lite/micro/test_helpers.d 

OBJS += \
./lite/micro/all_ops_resolver.o \
./lite/micro/fake_micro_context.o \
./lite/micro/flatbuffer_utils.o \
./lite/micro/memory_helpers.o \
./lite/micro/micro_allocation_info.o \
./lite/micro/micro_allocator.o \
./lite/micro/micro_context.o \
./lite/micro/micro_error_reporter.o \
./lite/micro/micro_graph.o \
./lite/micro/micro_interpreter.o \
./lite/micro/micro_profiler.o \
./lite/micro/micro_resource_variable.o \
./lite/micro/micro_string.o \
./lite/micro/micro_time.o \
./lite/micro/micro_utils.o \
./lite/micro/mock_micro_graph.o \
./lite/micro/recording_micro_allocator.o \
./lite/micro/system_setup.o \
./lite/micro/test_helper_custom_ops.o \
./lite/micro/test_helpers.o 


# Each subdirectory must supply rules for building sources it contributes
lite/micro/%.o lite/micro/%.su lite/micro/%.cyclo: ../lite/micro/%.cc lite/micro/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/ruy" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lite-2f-micro

clean-lite-2f-micro:
	-$(RM) ./lite/micro/all_ops_resolver.cyclo ./lite/micro/all_ops_resolver.d ./lite/micro/all_ops_resolver.o ./lite/micro/all_ops_resolver.su ./lite/micro/fake_micro_context.cyclo ./lite/micro/fake_micro_context.d ./lite/micro/fake_micro_context.o ./lite/micro/fake_micro_context.su ./lite/micro/flatbuffer_utils.cyclo ./lite/micro/flatbuffer_utils.d ./lite/micro/flatbuffer_utils.o ./lite/micro/flatbuffer_utils.su ./lite/micro/memory_helpers.cyclo ./lite/micro/memory_helpers.d ./lite/micro/memory_helpers.o ./lite/micro/memory_helpers.su ./lite/micro/micro_allocation_info.cyclo ./lite/micro/micro_allocation_info.d ./lite/micro/micro_allocation_info.o ./lite/micro/micro_allocation_info.su ./lite/micro/micro_allocator.cyclo ./lite/micro/micro_allocator.d ./lite/micro/micro_allocator.o ./lite/micro/micro_allocator.su ./lite/micro/micro_context.cyclo ./lite/micro/micro_context.d ./lite/micro/micro_context.o ./lite/micro/micro_context.su ./lite/micro/micro_error_reporter.cyclo ./lite/micro/micro_error_reporter.d ./lite/micro/micro_error_reporter.o ./lite/micro/micro_error_reporter.su ./lite/micro/micro_graph.cyclo ./lite/micro/micro_graph.d ./lite/micro/micro_graph.o ./lite/micro/micro_graph.su ./lite/micro/micro_interpreter.cyclo ./lite/micro/micro_interpreter.d ./lite/micro/micro_interpreter.o ./lite/micro/micro_interpreter.su ./lite/micro/micro_profiler.cyclo ./lite/micro/micro_profiler.d ./lite/micro/micro_profiler.o ./lite/micro/micro_profiler.su ./lite/micro/micro_resource_variable.cyclo ./lite/micro/micro_resource_variable.d ./lite/micro/micro_resource_variable.o ./lite/micro/micro_resource_variable.su ./lite/micro/micro_string.cyclo ./lite/micro/micro_string.d ./lite/micro/micro_string.o ./lite/micro/micro_string.su ./lite/micro/micro_time.cyclo ./lite/micro/micro_time.d ./lite/micro/micro_time.o ./lite/micro/micro_time.su ./lite/micro/micro_utils.cyclo ./lite/micro/micro_utils.d ./lite/micro/micro_utils.o ./lite/micro/micro_utils.su ./lite/micro/mock_micro_graph.cyclo ./lite/micro/mock_micro_graph.d ./lite/micro/mock_micro_graph.o ./lite/micro/mock_micro_graph.su ./lite/micro/recording_micro_allocator.cyclo ./lite/micro/recording_micro_allocator.d ./lite/micro/recording_micro_allocator.o ./lite/micro/recording_micro_allocator.su ./lite/micro/system_setup.cyclo ./lite/micro/system_setup.d ./lite/micro/system_setup.o ./lite/micro/system_setup.su ./lite/micro/test_helper_custom_ops.cyclo ./lite/micro/test_helper_custom_ops.d ./lite/micro/test_helper_custom_ops.o ./lite/micro/test_helper_custom_ops.su ./lite/micro/test_helpers.cyclo ./lite/micro/test_helpers.d ./lite/micro/test_helpers.o ./lite/micro/test_helpers.su

.PHONY: clean-lite-2f-micro

