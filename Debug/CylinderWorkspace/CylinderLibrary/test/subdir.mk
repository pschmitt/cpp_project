################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CylinderWorkspace/CylinderLibrary/test/cylinderLibrayTester.c 

OBJS += \
./CylinderWorkspace/CylinderLibrary/test/cylinderLibrayTester.o 

C_DEPS += \
./CylinderWorkspace/CylinderLibrary/test/cylinderLibrayTester.d 


# Each subdirectory must supply rules for building sources it contributes
CylinderWorkspace/CylinderLibrary/test/%.o: ../CylinderWorkspace/CylinderLibrary/test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


