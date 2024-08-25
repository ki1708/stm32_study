################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/src/adc.c \
../App/src/cli.c \
../App/src/uart.c \
../App/src/utils.c 

OBJS += \
./App/src/adc.o \
./App/src/cli.o \
./App/src/uart.o \
./App/src/utils.o 

C_DEPS += \
./App/src/adc.d \
./App/src/cli.d \
./App/src/uart.d \
./App/src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
App/src/%.o App/src/%.su App/src/%.cyclo: ../App/src/%.c App/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ki170/Desktop/stm32workspace/CLI/App" -I"C:/Users/ki170/Desktop/stm32workspace/CLI/App/include" -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-src

clean-App-2f-src:
	-$(RM) ./App/src/adc.cyclo ./App/src/adc.d ./App/src/adc.o ./App/src/adc.su ./App/src/cli.cyclo ./App/src/cli.d ./App/src/cli.o ./App/src/cli.su ./App/src/uart.cyclo ./App/src/uart.d ./App/src/uart.o ./App/src/uart.su ./App/src/utils.cyclo ./App/src/utils.d ./App/src/utils.o ./App/src/utils.su

.PHONY: clean-App-2f-src

