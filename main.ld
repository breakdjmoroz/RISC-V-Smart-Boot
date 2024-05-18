MEMORY
{
	bootloader_space (rwx) : ORIGIN = 0x80001000, LENGTH = 2048 
	helpers (rwx) : ORIGIN = 0x80002000, LENGTH = 64K
}

SECTIONS
{
	.text : {obj/main.o(.text)} > bootloader_space
	.text : {*.o(.text)} > helpers
  .data . : {*.o(.data)}
  .bss . : {*.o(.bss)}
}
