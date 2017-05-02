################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 

CPP_SRCS:= $(shell find ./src -name "*.cpp")
TEMP:= $(notdir $(CPP_SRCS:%.cpp=%.o))
OBJS:= $(addprefix ./build/, $(TEMP))
CPP_DEPS:= $(addprefix ./build/, $(TEMP:%.o=%.d))

	



# Each subdirectory must supply rules for building sources it contributes
build/%.o: ./src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"./includes" -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


