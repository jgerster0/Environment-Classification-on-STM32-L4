################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.c \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.c \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.c \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.c \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.c \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.c \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.c \
../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.c 

C_DEPS += \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.d \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.d \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.d \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.d \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.d \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.d \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.d \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.d 

OBJS += \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.o \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.o \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.o \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.o \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.o \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.o \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.o \
./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/%.o Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/%.su Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/%.cyclo: ../Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/%.c Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/ruy" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS1-2f-DSP-2f-Source-2f-QuaternionMathFunctions

clean-Drivers-2f-CMSIS1-2f-DSP-2f-Source-2f-QuaternionMathFunctions:
	-$(RM) ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion2rotation_f32.su ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_conjugate_f32.su ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_inverse_f32.su ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_norm_f32.su ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_normalize_f32.su ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_f32.su ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_quaternion_product_single_f32.su ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.cyclo ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.d ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.o ./Drivers/CMSIS1/DSP/Source/QuaternionMathFunctions/arm_rotation2quaternion_f32.su

.PHONY: clean-Drivers-2f-CMSIS1-2f-DSP-2f-Source-2f-QuaternionMathFunctions

