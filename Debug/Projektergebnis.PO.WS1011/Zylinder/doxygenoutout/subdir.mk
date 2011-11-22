################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Projektergebnis.PO.WS1011/Zylinder/doxygenoutout/template-doxygen.c 

OBJS += \
./Projektergebnis.PO.WS1011/Zylinder/doxygenoutout/template-doxygen.o 

C_DEPS += \
./Projektergebnis.PO.WS1011/Zylinder/doxygenoutout/template-doxygen.d 


# Each subdirectory must supply rules for building sources it contributes
Projektergebnis.PO.WS1011/Zylinder/doxygenoutout/%.o: ../Projektergebnis.PO.WS1011/Zylinder/doxygenoutout/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


