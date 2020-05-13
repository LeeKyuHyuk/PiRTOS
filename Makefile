ARCH = armv6zk
MCPU = arm1176jzf-s

TARGET = rpi-zero

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-gcc
OC = arm-none-eabi-objcopy

LINKER_SCRIPT = pirtos.ld
MAP_FILE = build/pirtos.map

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.o, $(ASM_SRCS))

VPATH = boot 			\
        hal/$(TARGET)	\
        lib

C_SRCS  = $(notdir $(wildcard boot/*.c))
C_SRCS += $(notdir $(wildcard hal/$(TARGET)/*.c))
C_SRCS += $(notdir $(wildcard lib/*.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

INC_DIRS  = -I include 			\
            -I hal	   			\
            -I hal/$(TARGET)	\
            -I lib

CFLAGS = -c -g -std=gnu99 -mthumb-interwork

LDFLAGS = -nostartfiles -nostdlib -nodefaultlibs -static -lgcc

pirtos = build/pirtos.elf
pirtos_bin = build/pirtos.img

.PHONY: all clean run debug gdb

all: $(pirtos)

clean:
	@rm -fr build

run: $(pirtos)
	qemu-system-arm -M raspi2 -kernel $(pirtos) -serial stdio

debug: $(pirtos)
	qemu-system-arm -M raspi2 -kernel $(pirtos) -serial stdio -S -gdb tcp::8080,ipv4

gdb:
	arm-none-eabi-gdb

$(pirtos): $(ASM_OBJS) $(C_OBJS) $(LINKER_SCRIPT)
	$(LD) -n -T $(LINKER_SCRIPT) -o $(pirtos) $(ASM_OBJS) $(C_OBJS) -Wl,-Map=$(MAP_FILE) $(LDFLAGS)
	$(OC) $(pirtos) -O binary $(pirtos_bin)

build/%.o: %.S
	mkdir -p $(shell dirname $@)
	$(CC) -march=$(ARCH) -mcpu=$(MCPU) -marm $(INC_DIRS) $(CFLAGS) -o $@ $<

build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -march=$(ARCH) -mcpu=$(MCPU) -marm $(INC_DIRS) $(CFLAGS) -o $@ $<
