################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/CylinderApplication.main.c \
../Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/cylinderIO.c 

OBJS += \
./Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/CylinderApplication.main.o \
./Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/cylinderIO.o 

C_DEPS += \
./Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/CylinderApplication.main.d \
./Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/cylinderIO.d 


# Each subdirectory must supply rules for building sources it contributes
Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/%.o: ../Projektergebnis.PO.WS1011/Zylinder/Exemple_Cylinder/CylinderApplication/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


