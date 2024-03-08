MEMORY
{
	bootloader_space (rwx) : ORIGIN = 0x80000100, LENGTH = 32K
}

SECTIONS
{
	.text : {*.o(.text)} > bootloader_space
}
