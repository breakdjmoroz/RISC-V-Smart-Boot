MEMORY
{
	bootloader_space (rwx) : ORIGIN = 0x80001000, LENGTH = 32K
}

SECTIONS
{
	.text : {*.o(.text)} > bootloader_space
}
