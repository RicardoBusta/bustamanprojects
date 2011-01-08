################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RGINE/RGLText.cpp \
../src/RGINE/RGame.cpp \
../src/RGINE/RSDL.cpp 

OBJS += \
./src/RGINE/RGLText.o \
./src/RGINE/RGame.o \
./src/RGINE/RSDL.o 

CPP_DEPS += \
./src/RGINE/RGLText.d \
./src/RGINE/RGame.d \
./src/RGINE/RSDL.d 


# Each subdirectory must supply rules for building sources it contributes
src/RGINE/%.o: ../src/RGINE/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


