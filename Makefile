ARCH = armv6zk
MCPU = arm1176jzf-s

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OC = arm-none-eabi-objcopy

LINKER_SCRIPT = pirtos.ld

ASM_SRCS = $(wildcard *.S)
ASM_OBJS = $(patsubst %.S, build/%.o, $(ASM_SRCS))

pirtos = build/pirtos.elf
pirtos_bin = build/pirtos.bin

.PHONY: all clean run debug gdb

all: $(pirtos)

clean:
	rm -rf build

run: $(pirtos)
	qemu-system-arm -M raspi2 -kernel $(pirtos)

debug: $(pirtos)
	qemu-system-arm -M raspi2 -kernel $(pirtos) -S -gdb tcp::8080,ipv4

gdb:
	arm-none-eabi-gdb

$(pirtos): $(ASM_OBJS) $(LINKER_SCRIPT)
	$(LD) -n -T $(LINKER_SCRIPT) -nostdlib -o $(pirtos) $(ASM_OBJS)
	$(OC) -O binary $(pirtos) $(pirtos_bin)

build/%.o: %.S
	mkdir -p $(shell dirname $@)
	$(AS) -march=$(ARCH) -mcpu=$(MCPU) -g -o $@ $<
