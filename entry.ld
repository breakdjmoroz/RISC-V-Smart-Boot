MEMORY
{
 entry (rwx) : ORIGIN = 0x80000000, LENGTH = 64
}
SECTIONS
{
 .text : {*.obj(.text)} > entry
}
