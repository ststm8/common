CC=sdcc
INCLUDES=-Iheaders/include
CFLAGS=-D$(STM8_MCU) $(INCLUDES) -mstm8 --std-c23
LDFLAGS=-mstm8
PS=powershell -NoProfile -NonInteractive
MKDIR =	$(PS) "New-Item -ItemType Directory $(1) | Out-Null"

.PHONY: clean all folders

all: folders build/main.ihx

hdrs := $(wildcard *.h)
srcs := $(wildcard *.c)
mods := $(wildcard */module.mk)
fldrs := $(dir $(mods))
build_fldrs := $(patsubst %/,build/%,$(fldrs))

INCLUDES += $(patsubst %/,-I%,$(fldrs))

build $(build_fldrs):
	$(call MKDIR,$@)

folders: build $(build_fldrs)

include $(mods)

objs := $(patsubst %.c,build/%.rel,$(srcs))

build/main.ihx : $(objs)
	@echo *** LINKING HEX
	$(CC) $(LDFLAGS) $^ -o $@

build/%.rel: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	$(PS) "if (Test-Path build) { rm -r build }"

flash: all
	@echo *** FLASHING
	openocd -f interface/stlink-dap.cfg -f target/$(STM8_MCU_OCD).cfg -f ./stm8.cfg -c init -c "program_device build/main.ihx 0"