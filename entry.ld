MEMORY
{
	entry_point (rx) : ORIGIN = 0x80000000, LENGTH = 64
}

SECTIONS
{
	.text : {fsbl.obj(.text)} > entry_point
}
