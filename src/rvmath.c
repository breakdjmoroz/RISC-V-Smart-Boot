#include "../hdr/rvmath.h"

unsigned int i_div(const unsigned int a, const unsigned int b)  
{
  __asm__
    (
     	"div:\n\t"
	"ADD t0, zero, a0\n\t"
	"ADD t1, zero, a1\n\t"

	"loop_div:\n\t"
	"BLT t0, t1, end_div\n\t"
	"SUB t0, t0, t1\n\t"
	"ADDI t2, t2, 1\n\t"
	"JAL zero, loop_div\n\t"

	"end_div:\n\t"
	"ADD a0, zero, t2\n\t"
	"ret \n"

     );
}

unsigned int i_mod(const unsigned int a,const unsigned int b)
{
  __asm__
    (
     	"mod:\n\t"
	"ADD t0, zero, a0\n\t"
	"ADD t1, zero, a1\n\t"

	"loop_mod:"
	"BLT t0, t1, end_mod\n\t"
	"SUB t0, t0, t1\n\t"
	"JAL zero, loop_mod\n\t"

	"end_mod:\n\t"
	"ADD a0, zero, t0\n\t"
	"ret \n"
     );
}
