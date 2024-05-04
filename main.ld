MEMORY
{
	bootloader_space (rwx) : ORIGIN = 0x80001000, LENGTH = 64K
}

SECTIONS
{
	.text : {*.o(.text)} > bootloader_space
  .data . : {*.o(.data)}
  .bss . : {*.o(.bss)}
}
