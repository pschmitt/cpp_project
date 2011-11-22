################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ws_n_prj/Main.cpp \
../ws_n_prj/Project.cpp \
../ws_n_prj/ProjectException.cpp \
../ws_n_prj/Workspace.cpp \
../ws_n_prj/WorkspaceException.cpp 

OBJS += \
./ws_n_prj/Main.o \
./ws_n_prj/Project.o \
./ws_n_prj/ProjectException.o \
./ws_n_prj/Workspace.o \
./ws_n_prj/WorkspaceException.o 

CPP_DEPS += \
./ws_n_prj/Main.d \
./ws_n_prj/Project.d \
./ws_n_prj/ProjectException.d \
./ws_n_prj/Workspace.d \
./ws_n_prj/WorkspaceException.d 


# Each subdirectory must supply rules for building sources it contributes
ws_n_prj/%.o: ../ws_n_prj/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


