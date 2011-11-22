################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CylinderWorkspace/CylinderLibrary/src/circle.c \
../CylinderWorkspace/CylinderLibrary/src/cylinder.c 

OBJS += \
./CylinderWorkspace/CylinderLibrary/src/circle.o \
./CylinderWorkspace/CylinderLibrary/src/cylinder.o 

C_DEPS += \
./CylinderWorkspace/CylinderLibrary/src/circle.d \
./CylinderWorkspace/CylinderLibrary/src/cylinder.d 


# Each subdirectory must supply rules for building sources it contributes
CylinderWorkspace/CylinderLibrary/src/%.o: ../CylinderWorkspace/CylinderLibrary/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


