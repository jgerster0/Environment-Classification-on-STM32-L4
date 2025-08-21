################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../X-CUBE-AI/App/aiPbIO.c \
../X-CUBE-AI/App/aiPbMemRWServices.c \
../X-CUBE-AI/App/aiPbMgr.c \
../X-CUBE-AI/App/aiTestHelper.c \
../X-CUBE-AI/App/aiTestUtility.c \
../X-CUBE-AI/App/aiValidation.c \
../X-CUBE-AI/App/ai_device_adaptor.c \
../X-CUBE-AI/App/app_x-cube-ai.c \
../X-CUBE-AI/App/cidar_model.c \
../X-CUBE-AI/App/cidar_model_data.c \
../X-CUBE-AI/App/cidar_model_data_params.c \
../X-CUBE-AI/App/cifar_model.c \
../X-CUBE-AI/App/cifar_model_data.c \
../X-CUBE-AI/App/cifar_model_data_params.c \
../X-CUBE-AI/App/lc_print.c \
../X-CUBE-AI/App/network_1.c \
../X-CUBE-AI/App/network_1_data.c \
../X-CUBE-AI/App/network_1_data_params.c \
../X-CUBE-AI/App/pb_common.c \
../X-CUBE-AI/App/pb_decode.c \
../X-CUBE-AI/App/pb_encode.c \
../X-CUBE-AI/App/pqat_model.c \
../X-CUBE-AI/App/pqat_model_data.c \
../X-CUBE-AI/App/pqat_model_data_params.c \
../X-CUBE-AI/App/stm32msg.pb.c \
../X-CUBE-AI/App/syscalls.c 

C_DEPS += \
./X-CUBE-AI/App/aiPbIO.d \
./X-CUBE-AI/App/aiPbMemRWServices.d \
./X-CUBE-AI/App/aiPbMgr.d \
./X-CUBE-AI/App/aiTestHelper.d \
./X-CUBE-AI/App/aiTestUtility.d \
./X-CUBE-AI/App/aiValidation.d \
./X-CUBE-AI/App/ai_device_adaptor.d \
./X-CUBE-AI/App/app_x-cube-ai.d \
./X-CUBE-AI/App/cidar_model.d \
./X-CUBE-AI/App/cidar_model_data.d \
./X-CUBE-AI/App/cidar_model_data_params.d \
./X-CUBE-AI/App/cifar_model.d \
./X-CUBE-AI/App/cifar_model_data.d \
./X-CUBE-AI/App/cifar_model_data_params.d \
./X-CUBE-AI/App/lc_print.d \
./X-CUBE-AI/App/network_1.d \
./X-CUBE-AI/App/network_1_data.d \
./X-CUBE-AI/App/network_1_data_params.d \
./X-CUBE-AI/App/pb_common.d \
./X-CUBE-AI/App/pb_decode.d \
./X-CUBE-AI/App/pb_encode.d \
./X-CUBE-AI/App/pqat_model.d \
./X-CUBE-AI/App/pqat_model_data.d \
./X-CUBE-AI/App/pqat_model_data_params.d \
./X-CUBE-AI/App/stm32msg.pb.d \
./X-CUBE-AI/App/syscalls.d 

OBJS += \
./X-CUBE-AI/App/aiPbIO.o \
./X-CUBE-AI/App/aiPbMemRWServices.o \
./X-CUBE-AI/App/aiPbMgr.o \
./X-CUBE-AI/App/aiTestHelper.o \
./X-CUBE-AI/App/aiTestUtility.o \
./X-CUBE-AI/App/aiValidation.o \
./X-CUBE-AI/App/ai_device_adaptor.o \
./X-CUBE-AI/App/app_x-cube-ai.o \
./X-CUBE-AI/App/cidar_model.o \
./X-CUBE-AI/App/cidar_model_data.o \
./X-CUBE-AI/App/cidar_model_data_params.o \
./X-CUBE-AI/App/cifar_model.o \
./X-CUBE-AI/App/cifar_model_data.o \
./X-CUBE-AI/App/cifar_model_data_params.o \
./X-CUBE-AI/App/lc_print.o \
./X-CUBE-AI/App/network_1.o \
./X-CUBE-AI/App/network_1_data.o \
./X-CUBE-AI/App/network_1_data_params.o \
./X-CUBE-AI/App/pb_common.o \
./X-CUBE-AI/App/pb_decode.o \
./X-CUBE-AI/App/pb_encode.o \
./X-CUBE-AI/App/pqat_model.o \
./X-CUBE-AI/App/pqat_model_data.o \
./X-CUBE-AI/App/pqat_model_data_params.o \
./X-CUBE-AI/App/stm32msg.pb.o \
./X-CUBE-AI/App/syscalls.o 


# Each subdirectory must supply rules for building sources it contributes
X-CUBE-AI/App/%.o X-CUBE-AI/App/%.su X-CUBE-AI/App/%.cyclo: ../X-CUBE-AI/App/%.c X-CUBE-AI/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/schema" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/kernels" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/tensorflow/lite/micro/memory_planner" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/UrbanSound8K_QAT/tensorflow_lite/third_party/ruy" -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-X-2d-CUBE-2d-AI-2f-App

clean-X-2d-CUBE-2d-AI-2f-App:
	-$(RM) ./X-CUBE-AI/App/aiPbIO.cyclo ./X-CUBE-AI/App/aiPbIO.d ./X-CUBE-AI/App/aiPbIO.o ./X-CUBE-AI/App/aiPbIO.su ./X-CUBE-AI/App/aiPbMemRWServices.cyclo ./X-CUBE-AI/App/aiPbMemRWServices.d ./X-CUBE-AI/App/aiPbMemRWServices.o ./X-CUBE-AI/App/aiPbMemRWServices.su ./X-CUBE-AI/App/aiPbMgr.cyclo ./X-CUBE-AI/App/aiPbMgr.d ./X-CUBE-AI/App/aiPbMgr.o ./X-CUBE-AI/App/aiPbMgr.su ./X-CUBE-AI/App/aiTestHelper.cyclo ./X-CUBE-AI/App/aiTestHelper.d ./X-CUBE-AI/App/aiTestHelper.o ./X-CUBE-AI/App/aiTestHelper.su ./X-CUBE-AI/App/aiTestUtility.cyclo ./X-CUBE-AI/App/aiTestUtility.d ./X-CUBE-AI/App/aiTestUtility.o ./X-CUBE-AI/App/aiTestUtility.su ./X-CUBE-AI/App/aiValidation.cyclo ./X-CUBE-AI/App/aiValidation.d ./X-CUBE-AI/App/aiValidation.o ./X-CUBE-AI/App/aiValidation.su ./X-CUBE-AI/App/ai_device_adaptor.cyclo ./X-CUBE-AI/App/ai_device_adaptor.d ./X-CUBE-AI/App/ai_device_adaptor.o ./X-CUBE-AI/App/ai_device_adaptor.su ./X-CUBE-AI/App/app_x-cube-ai.cyclo ./X-CUBE-AI/App/app_x-cube-ai.d ./X-CUBE-AI/App/app_x-cube-ai.o ./X-CUBE-AI/App/app_x-cube-ai.su ./X-CUBE-AI/App/cidar_model.cyclo ./X-CUBE-AI/App/cidar_model.d ./X-CUBE-AI/App/cidar_model.o ./X-CUBE-AI/App/cidar_model.su ./X-CUBE-AI/App/cidar_model_data.cyclo ./X-CUBE-AI/App/cidar_model_data.d ./X-CUBE-AI/App/cidar_model_data.o ./X-CUBE-AI/App/cidar_model_data.su ./X-CUBE-AI/App/cidar_model_data_params.cyclo ./X-CUBE-AI/App/cidar_model_data_params.d ./X-CUBE-AI/App/cidar_model_data_params.o ./X-CUBE-AI/App/cidar_model_data_params.su ./X-CUBE-AI/App/cifar_model.cyclo ./X-CUBE-AI/App/cifar_model.d ./X-CUBE-AI/App/cifar_model.o ./X-CUBE-AI/App/cifar_model.su ./X-CUBE-AI/App/cifar_model_data.cyclo ./X-CUBE-AI/App/cifar_model_data.d ./X-CUBE-AI/App/cifar_model_data.o ./X-CUBE-AI/App/cifar_model_data.su ./X-CUBE-AI/App/cifar_model_data_params.cyclo ./X-CUBE-AI/App/cifar_model_data_params.d ./X-CUBE-AI/App/cifar_model_data_params.o ./X-CUBE-AI/App/cifar_model_data_params.su ./X-CUBE-AI/App/lc_print.cyclo ./X-CUBE-AI/App/lc_print.d ./X-CUBE-AI/App/lc_print.o ./X-CUBE-AI/App/lc_print.su ./X-CUBE-AI/App/network_1.cyclo ./X-CUBE-AI/App/network_1.d ./X-CUBE-AI/App/network_1.o ./X-CUBE-AI/App/network_1.su ./X-CUBE-AI/App/network_1_data.cyclo ./X-CUBE-AI/App/network_1_data.d ./X-CUBE-AI/App/network_1_data.o ./X-CUBE-AI/App/network_1_data.su ./X-CUBE-AI/App/network_1_data_params.cyclo ./X-CUBE-AI/App/network_1_data_params.d ./X-CUBE-AI/App/network_1_data_params.o ./X-CUBE-AI/App/network_1_data_params.su ./X-CUBE-AI/App/pb_common.cyclo ./X-CUBE-AI/App/pb_common.d ./X-CUBE-AI/App/pb_common.o ./X-CUBE-AI/App/pb_common.su ./X-CUBE-AI/App/pb_decode.cyclo ./X-CUBE-AI/App/pb_decode.d ./X-CUBE-AI/App/pb_decode.o ./X-CUBE-AI/App/pb_decode.su ./X-CUBE-AI/App/pb_encode.cyclo ./X-CUBE-AI/App/pb_encode.d ./X-CUBE-AI/App/pb_encode.o ./X-CUBE-AI/App/pb_encode.su ./X-CUBE-AI/App/pqat_model.cyclo ./X-CUBE-AI/App/pqat_model.d ./X-CUBE-AI/App/pqat_model.o ./X-CUBE-AI/App/pqat_model.su ./X-CUBE-AI/App/pqat_model_data.cyclo ./X-CUBE-AI/App/pqat_model_data.d ./X-CUBE-AI/App/pqat_model_data.o ./X-CUBE-AI/App/pqat_model_data.su ./X-CUBE-AI/App/pqat_model_data_params.cyclo ./X-CUBE-AI/App/pqat_model_data_params.d ./X-CUBE-AI/App/pqat_model_data_params.o ./X-CUBE-AI/App/pqat_model_data_params.su ./X-CUBE-AI/App/stm32msg.pb.cyclo ./X-CUBE-AI/App/stm32msg.pb.d ./X-CUBE-AI/App/stm32msg.pb.o ./X-CUBE-AI/App/stm32msg.pb.su ./X-CUBE-AI/App/syscalls.cyclo ./X-CUBE-AI/App/syscalls.d ./X-CUBE-AI/App/syscalls.o ./X-CUBE-AI/App/syscalls.su

.PHONY: clean-X-2d-CUBE-2d-AI-2f-App

