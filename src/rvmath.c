#include "../hdr/rvmath.h"

unsigned int i_div(const unsigned int a, const unsigned int b)  
{
  unsigned int result = (unsigned int)a;
  __asm__
    (
     	"div:\n\t"
	"ADD t0, zero, %0\n\t"
	"ADD t1, zero, %1\n\t"
	"ADDI t2, zero, 0\n\t"

	  
	"loop_div:\n\t"
	"BLTU t0, t1, end_div\n\t"
	"SUB t0, t0, t1\n\t"
	"ADDI t2, t2, 1\n\t"
	"JAL zero, loop_div\n\t"

	"end_div:\n\t"
	"ADD %0, zero, t2\n\t"
  : "+r" (result)
  : "r" (b)
     );
  return result;
}

unsigned int i_mod(const unsigned int a,const unsigned int b)
{
  unsigned int result = (unsigned int)a;
  __asm__
    (
     	"mod:\n\t"
	"ADD t0, zero, %0\n\t"
	"ADD t1, zero, %1\n\t"

	"loop_mod:"
	"BLTU t0, t1, end_mod\n\t"
	"SUB t0, t0, t1\n\t"
	"JAL zero, loop_mod\n\t"

	"end_mod:\n\t"
	"ADD %0, zero, t0\n\t"
  : "+r" (result)
  : "r" (b)
     );

  return result;
}
