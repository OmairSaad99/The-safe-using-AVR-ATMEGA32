################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
The_Safe.lss \

FLASH_IMAGE += \
The_Safe.hex \

EEPROM_IMAGE += \
The_Safe.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: The_Safe.elf secondary-outputs

# Tool invocations
The_Safe.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,The_Safe.map -mmcu=atmega32 -o "The_Safe.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

The_Safe.lss: The_Safe.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S The_Safe.elf  >"The_Safe.lss"
	@echo 'Finished building: $@'
	@echo ' '

The_Safe.hex: The_Safe.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex The_Safe.elf  "The_Safe.hex"
	@echo 'Finished building: $@'
	@echo ' '

The_Safe.eep: The_Safe.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex The_Safe.elf  "The_Safe.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: The_Safe.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 The_Safe.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) The_Safe.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
