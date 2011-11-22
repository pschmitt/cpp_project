################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Projektergebnis.PO.WS1011/CSourceGenerator/Component.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Enumeration.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Function.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Identifier.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Library.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/LibraryException.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Main.Object.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/MegaMain.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Object.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Parameter.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Program.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/ProgrammException.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Project.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/ProjectException.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Structur.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Symbol.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/Workspace.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/WorkspaceException.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/main.StructurEnum.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/main.module.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/main.streams.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/mainJunit.cpp \
../Projektergebnis.PO.WS1011/CSourceGenerator/module.cpp 

OBJS += \
./Projektergebnis.PO.WS1011/CSourceGenerator/Component.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Enumeration.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Function.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Identifier.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Library.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/LibraryException.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Main.Object.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/MegaMain.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Object.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Parameter.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Program.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/ProgrammException.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Project.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/ProjectException.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Structur.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Symbol.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/Workspace.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/WorkspaceException.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/main.StructurEnum.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/main.module.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/main.streams.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/mainJunit.o \
./Projektergebnis.PO.WS1011/CSourceGenerator/module.o 

CPP_DEPS += \
./Projektergebnis.PO.WS1011/CSourceGenerator/Component.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Enumeration.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Function.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Identifier.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Library.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/LibraryException.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Main.Object.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/MegaMain.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Object.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Parameter.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Program.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/ProgrammException.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Project.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/ProjectException.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Structur.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Symbol.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/Workspace.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/WorkspaceException.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/main.StructurEnum.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/main.module.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/main.streams.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/mainJunit.d \
./Projektergebnis.PO.WS1011/CSourceGenerator/module.d 


# Each subdirectory must supply rules for building sources it contributes
Projektergebnis.PO.WS1011/CSourceGenerator/%.o: ../Projektergebnis.PO.WS1011/CSourceGenerator/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


