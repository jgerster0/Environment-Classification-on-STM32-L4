################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.c \
../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.c 

C_DEPS += \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.d \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.d 

OBJS += \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.o \
./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS1/DSP/Source/InterpolationFunctions/%.o Drivers/CMSIS1/DSP/Source/InterpolationFunctions/%.su Drivers/CMSIS1/DSP/Source/InterpolationFunctions/%.cyclo: ../Drivers/CMSIS1/DSP/Source/InterpolationFunctions/%.c Drivers/CMSIS1/DSP/Source/InterpolationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L475xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-AI -I../X-CUBE-AI/Target -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/Core/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/PrivateInclude" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/DSP/Include/dsp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/Drivers/CMSIS/NN/Include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/tensorflow/lite/micro" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/flatbuffers/include" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/gemmlowp" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/kissfft" -I"/Users/jeremygerster/STM32CubeIDE/workspace_1.17.0/zuart_conn/tensorflow_lite/third_party/ruy" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS1-2f-DSP-2f-Source-2f-InterpolationFunctions

clean-Drivers-2f-CMSIS1-2f-DSP-2f-Source-2f-InterpolationFunctions:
	-$(RM) ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f16.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_f32.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q15.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q31.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_bilinear_interp_q7.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f16.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_f32.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q15.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q31.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_linear_interp_q7.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_f32.su ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.cyclo ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.d ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.o ./Drivers/CMSIS1/DSP/Source/InterpolationFunctions/arm_spline_interp_init_f32.su

.PHONY: clean-Drivers-2f-CMSIS1-2f-DSP-2f-Source-2f-InterpolationFunctions

