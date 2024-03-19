################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO_prog.c \
../EXTI_Prog.c \
../Global_prog.c \
../KPD_prog.c \
../TWI_Prog.c \
../The_Safe_prog.c \
../main.c 

OBJS += \
./CLCD_program.o \
./DIO_prog.o \
./EXTI_Prog.o \
./Global_prog.o \
./KPD_prog.o \
./TWI_Prog.o \
./The_Safe_prog.o \
./main.o 

C_DEPS += \
./CLCD_program.d \
./DIO_prog.d \
./EXTI_Prog.d \
./Global_prog.d \
./KPD_prog.d \
./TWI_Prog.d \
./The_Safe_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


