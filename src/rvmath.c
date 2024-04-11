#include "../hdr/rvmath.h"

unsigned long long i_div(const unsigned long long a, const unsigned long long b)  
{
  unsigned long long result = (unsigned long long)a;
  __asm__
    (
     	"div:\n\t"
	"ADD a0, zero, %0\n\t"
	"ADD a1, zero, %1\n\t"
	"ADDI a2, zero, 0x0\n\t"

	  
	"loop_div:\n\t"
	"BLTU a0, a1, end_div\n\t"
	"SUB a0, a0, a1\n\t"
	"ADDI a2, a2, 1\n\t"
	"JAL zero, loop_div\n\t"

	"end_div:\n\t"
	"ADD %0, zero, a2\n\t"
  : "+r" (result)
  : "r" (b)
     );
  return result;
}

unsigned long long i_mod(const unsigned long long a,const unsigned long long b)
{
  unsigned long long result = (unsigned long long)a;
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
