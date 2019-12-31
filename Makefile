EABI = arm-none-eabi
CC 	 = $(EABI)-gcc
LD 	 = $(EABI)-ld
AS 	 = $(EABI)-as

CPU   = cortex-m0
MARCH = armv6-m


COMPILER_OPTION =
COMPILER_OPTION += --specs=nosys.specs
COMPILER_OPTION += -mcpu=$(CPU)
COMPILER_OPTION += -mtune=$(CPU)
COMPILER_OPTION += -march=$(MARCH)
COMPILER_OPTION += -msoft-float
COMPILER_OPTION += -mfloat-abi=softfp
COMPILER_OPTION += -mthumb
