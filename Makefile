PROGRAM_NAME=smartboot.out
ENTRY_NAME=fsbl.out

AS=riscv64-unknown-elf-as
GCC=riscv64-unknown-elf-gcc
LD=riscv64-unknown-elf-ld

																		#ld scripts
GCC_LDSCRIPT=main.ld
AS_LDSCRIPT=entry.ld

																		#architecture configuration
MABI=ilp32
MARCH=rv32i_zicsr
TARGET=elf32-littleriscv

EMU=qemu-system-riscv64
EMU_MACHINE=virt

 																		#directories
ROOT=$(CURDIR)
SOURCE_DIR=src
OBJECT_DIR=obj
HEADER_DIR=hdr
EXECUT_DIR=exe

																		#flags
GCC_CFLAGS=-march=$(MARCH) -mabi=$(MABI) -c
GCC_LFLAGS=-b $(TARGET) -T $(GCC_LDSCRIPT)
AS_LFLAGS=-b $(TARGET) -T $(AS_LDSCRIPT)
EMU_FLAGS=-machine $(EMU_MACHINE)

SOURCE=$(wildcard *.c)
ASMSRC=$(wildcarc *.s)
OBJECT=*.o
ASMOBJ=*.obj
HEADER=*.h

all: compile | link run

link: generate_dir | compile
	$(LD) $(GCC_LFLAGS) $(OBJECT_DIR)/$(OBJECT) -o $(EXECUT_DIR)/$(PROGRAM_NAME)
	$(LD) $(AS_LFLAGS) $(OBJECT_DIR)/$(ASMOBJ) -o $(EXECUT_DIR)/$(ENTRY_NAME)

compile: generate_dir $(HEADER_DIR)/$(HEADER)
	$(foreach SRC, $(SOURCE), $(GCC) $(GCC_CFLAGS) $(SOURCE_DIR)/$(SRC) -o $(OBJECT_DIR)/$(SRC:%.c=%.o);)
	$(foreach SRC, $(ASMSRC), $(AS) $(GCC_CFLAGS) $(SOURCE_DIR)/$(SRC) -o $(OBJECT_DIR)/$(SRC:%.s=%.obj);)

run: compile | link
	$(EMU) $(EMU_FLAGS) -bios $(EXECUT_DIR)/$(ENTRY_NAME) -kernel $(EXECUT_DIR)/$(PROGRAM_NAME)

generate_dir:
	if [ ! -d $(OBJECT_DIR) ]; then mkdir $(OBJECT_DIR); fi
	if [ ! -d $(EXECUT_DIR) ]; then mkdir $(EXECUT_DIR); fi

clean:
	if [ -d $(OBJECT_DIR) ]; then rm $(OBJECT_DIR)*; fi
	if [ -d $(EXECUT_DIR) ]; then rm $(EXECUT_DIR)*; fi
