################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bitmap.cpp \
../src/Combat.cpp \
../src/Dungeon.cpp \
../src/Map.cpp \
../src/Mob.cpp \
../src/Ray.cpp \
../src/Sprite.cpp \
../src/main.cpp 

OBJS += \
./src/Bitmap.o \
./src/Combat.o \
./src/Dungeon.o \
./src/Map.o \
./src/Mob.o \
./src/Ray.o \
./src/Sprite.o \
./src/main.o 

CPP_DEPS += \
./src/Bitmap.d \
./src/Combat.d \
./src/Dungeon.d \
./src/Map.d \
./src/Mob.d \
./src/Ray.d \
./src/Sprite.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


