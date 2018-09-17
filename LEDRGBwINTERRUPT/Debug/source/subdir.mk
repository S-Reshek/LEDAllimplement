################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Delay.c \
../source/GPIO.c \
../source/RGB.c \
../source/main.c 

OBJS += \
./source/Delay.o \
./source/GPIO.o \
./source/RGB.o \
./source/main.o 

C_DEPS += \
./source/Delay.d \
./source/GPIO.d \
./source/RGB.d \
./source/main.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCR_INTEGER_PRINTF -DSDK_DEBUGCONSOLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DCPU_MK64FN1M0VLL12_cm4 -DCPU_MK64FN1M0VLL12 -D__REDLIB__ -I"D:\Embebidos\LEDGPIOPITNVIC\LEDRGBwINTERRUPT\source" -I"D:\Embebidos\LEDGPIOPITNVIC\LEDRGBwINTERRUPT" -I"D:\Embebidos\LEDGPIOPITNVIC\LEDRGBwINTERRUPT\CMSIS" -I"D:\Embebidos\LEDGPIOPITNVIC\LEDRGBwINTERRUPT\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


