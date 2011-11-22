################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CylinderWorkspace/CylinderApplication/src/CylinderApplication.main.c \
../CylinderWorkspace/CylinderApplication/src/cylinderIO.c 

OBJS += \
./CylinderWorkspace/CylinderApplication/src/CylinderApplication.main.o \
./CylinderWorkspace/CylinderApplication/src/cylinderIO.o 

C_DEPS += \
./CylinderWorkspace/CylinderApplication/src/CylinderApplication.main.d \
./CylinderWorkspace/CylinderApplication/src/cylinderIO.d 


# Each subdirectory must supply rules for building sources it contributes
CylinderWorkspace/CylinderApplication/src/%.o: ../CylinderWorkspace/CylinderApplication/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


