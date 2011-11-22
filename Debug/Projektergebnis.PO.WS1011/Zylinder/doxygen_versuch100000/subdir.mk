################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Projektergebnis.PO.WS1011/Zylinder/doxygen_versuch100000/template-doxygen.o 

CPP_SRCS += \
../Projektergebnis.PO.WS1011/Zylinder/doxygen_versuch100000/template-doxygen.cpp 

OBJS += \
./Projektergebnis.PO.WS1011/Zylinder/doxygen_versuch100000/template-doxygen.o 

CPP_DEPS += \
./Projektergebnis.PO.WS1011/Zylinder/doxygen_versuch100000/template-doxygen.d 


# Each subdirectory must supply rules for building sources it contributes
Projektergebnis.PO.WS1011/Zylinder/doxygen_versuch100000/%.o: ../Projektergebnis.PO.WS1011/Zylinder/doxygen_versuch100000/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


