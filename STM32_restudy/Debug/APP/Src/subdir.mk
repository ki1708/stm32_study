################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Src/adc.c 

OBJS += \
./APP/Src/adc.o 

C_DEPS += \
./APP/Src/adc.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Src/%.o APP/Src/%.su APP/Src/%.cyclo: ../APP/Src/%.c APP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/addmin/Desktop/KGS/stm32_workspace/Stm32_Study/stm32_study/STM32_restudy/APP" -I"C:/Users/addmin/Desktop/KGS/stm32_workspace/Stm32_Study/stm32_study/STM32_restudy/APP/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-APP-2f-Src

clean-APP-2f-Src:
	-$(RM) ./APP/Src/adc.cyclo ./APP/Src/adc.d ./APP/Src/adc.o ./APP/Src/adc.su

.PHONY: clean-APP-2f-Src

