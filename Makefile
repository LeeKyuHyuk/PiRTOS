ARCH = armv6zk
MCPU = arm1176jzf-s

TARGET = rpi-zero

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OC = arm-none-eabi-objcopy

LINKER_SCRIPT = pirtos.ld
MAP_FILE = build/pirtos.map

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.o, $(ASM_SRCS))

VPATH = boot \
        hal/$(TARGET)

C_SRCS  = $(notdir $(wildcard boot/*.c))
C_SRCS += $(notdir $(wildcard hal/$(TARGET)/*.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

INC_DIRS  = -I include \
            -I hal \
            -I hal/$(TARGET)

CFLAGS = -c -g -std=gnu99

pirtos = build/pirtos.elf
pirtos_bin = build/pirtos.img

.PHONY: all clean run debug gdb

all: $(pirtos)

clean:
	@rm -fr build

run: $(pirtos)
	qemu-system-arm -M raspi2 -kernel $(pirtos) -serial null -serial stdio

debug: $(pirtos)
	qemu-system-arm -M raspi2 -kernel $(pirtos) -serial null -serial stdio -S -gdb tcp::1234,ipv4

gdb:
	arm-none-eabi-gdb

$(pirtos): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
	$(LD) -n -T $(LINKER_SCRIPT) -o $(pirtos) $(ASM_OBJS) $(C_OBJS) -Map=$(MAP_FILE)
	$(OC) $(pirtos) -O binary $(pirtos_bin)

build/%.o: %.S
	mkdir -p $(shell dirname $@)
	$(CC) -march=$(ARCH) -mcpu=$(MCPU) $(INC_DIRS) $(CFLAGS) -o $@ $<

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -march=$(ARCH) -mcpu=$(MCPU) $(INC_DIRS) $(CFLAGS) -o $@ $<