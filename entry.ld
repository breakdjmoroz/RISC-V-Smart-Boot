MEMORY
{
	entry_point (rx) : ORIGIN = 0x80000000, LENGTH = 64
}

SECTIONS
{
	.text : {obj/fsbl.obj(.text)} > entry_point
}
