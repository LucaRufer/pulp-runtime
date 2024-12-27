
PULP_LDFLAGS +=
PULP_CFLAGS += -D__cv32e40p__ -U__riscv__ -UARCHI_CORE_HAS_PULPV2

PULP_ARCH_CFLAGS    ?= -march=rv32imac_zfinx_xcorev -mabi=ilp32 -mno-pulp-hwloop
PULP_ARCH_LDFLAGS   ?= -march=rv32imac_zfinx_xcorev -mabi=ilp32 -mno-pulp-hwloop
PULP_ARCH_OBJDFLAGS ?=

PULP_CFLAGS    += -fdata-sections -ffunction-sections -include chips/dormouse/config.h -I$(PULPRT_HOME)/include/chips/dormouse
PULP_OMP_CFLAGS    += -fopenmp -mnativeomp
PULP_LDFLAGS += -nostartfiles -nostdlib -Wl,--gc-sections -L$(PULPRT_HOME)/kernel -lgcc

ifeq ($(DORMOUSE_DUALCORE), 1)
PULP_LDFLAGS += -Tchips/dormouse/link_dual_core.ld
else
PULP_LDFLAGS += -Tchips/dormouse/link.ld
endif

PULP_CC = riscv32-unknown-elf-gcc
PULP_AR ?= riscv32-unknown-elf-ar
PULP_LD ?= riscv32-unknown-elf-gcc
PULP_OBJDUMP ?= riscv32-unknown-elf-objdump

fc/archi=riscv
pe/archi=riscv
pulp_chip=dormouse
pulp_chip_family=dormouse

PULP_SRCS     += kernel/chips/dormouse/soc.c

include $(PULPRT_HOME)/rules/pulpos/configs/default.mk

ifeq '$(platform)' 'fpga'
CONFIG_IO_UART=1
endif

include $(PULPRT_HOME)/rules/pulpos/default_rules.mk
