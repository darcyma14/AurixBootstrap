################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/ssc/uart/src/subdir.mk
-include MCAL/ssc/tricore_general/src/subdir.mk
-include MCAL/ssc/spi/src/subdir.mk
-include MCAL/ssc/port/src/subdir.mk
-include MCAL/ssc/mcu/src/subdir.mk
-include MCAL/ssc/irq/src/subdir.mk
-include MCAL/ssc/icu/src/subdir.mk
-include MCAL/ssc/gpt/src/subdir.mk
-include MCAL/ssc/flsloader/src/subdir.mk
-include MCAL/ssc/dio/src/subdir.mk
-include MCAL/ssc/can/src/subdir.mk
-include MCAL/ssc/adc/src/subdir.mk
-include MCAL/ssc/Pwm/src/subdir.mk
-include MCAL/ssc/Lin/src/subdir.mk
-include MCAL/cfg/src/subdir.mk
-include FreeRTOS_V10_4_6/Source/Portable/Tasking/Tricore_TC23X_Demo/subdir.mk
-include FreeRTOS_V10_4_6/Source/Portable/MemMang/subdir.mk
-include FreeRTOS_V10_4_6/Source/subdir.mk
-include BSW/integration_general/src/subdir.mk
-include BSW/ecum/src/subdir.mk
-include APP/src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := CliDemo
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
CliDemo.siz \


# All Target
all: main-build

# Main-build Target
main-build: CliDemo.elf secondary-outputs

# Tool invocations
CliDemo.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS) .CliDemo.elf.opt
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc -f .CliDemo.elf.opt
	@echo 'Finished building target: $@'
	@echo ' '

.CliDemo.elf.opt:
	@argfile .CliDemo.elf.opt --lsl-file="../Lcf_Tasking_Tricore_Tc_freeRTOS.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="CliDemo.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=3 -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc23x -o"CliDemo.elf" -Wl-o"CliDemo.hex:IHEX" $(OBJS)

.PHONY: .CliDemo.elf.opt

CliDemo.siz: CliDemo.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "CliDemo.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) CliDemo.siz CliDemo.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
