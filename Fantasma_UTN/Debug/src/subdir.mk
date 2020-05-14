################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Fantasma_UTN.c \
../src/Ghost.c \
../src/utn.c 

OBJS += \
./src/Fantasma_UTN.o \
./src/Ghost.o \
./src/utn.o 

C_DEPS += \
./src/Fantasma_UTN.d \
./src/Ghost.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


