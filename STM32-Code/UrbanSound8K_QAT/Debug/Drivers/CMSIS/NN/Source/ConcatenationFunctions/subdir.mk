################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.c \
../Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.c \
../Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.c \
../Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.c 

C_DEPS += \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.d \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.d \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.d \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.d 

OBJS += \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.o \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.o \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.o \
./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/NN/Source/ConcatenationFunctions/%.o Drivers/CMSIS/NN/Source/ConcatenationFunctions/%.su Drivers/CMSIS/NN/Source/ConcatenationFunctions/%.cyclo: ../Drivers/CMSIS/NN/Source/ConcatenationFunctions/%.c Drivers/CMSIS/NN/Source/ConcatenationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/schema" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/kernels" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/micro/memory_planner" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/ruy" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-NN-2f-Source-2f-ConcatenationFunctions

clean-Drivers-2f-CMSIS-2f-NN-2f-Source-2f-ConcatenationFunctions:
	-$(RM) ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.cyclo ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.d ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.o ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_w.su ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.cyclo ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.d ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.o ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_x.su ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.cyclo ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.d ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.o ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_y.su ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.cyclo ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.d ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.o ./Drivers/CMSIS/NN/Source/ConcatenationFunctions/arm_concatenation_s8_z.su

.PHONY: clean-Drivers-2f-CMSIS-2f-NN-2f-Source-2f-ConcatenationFunctions

