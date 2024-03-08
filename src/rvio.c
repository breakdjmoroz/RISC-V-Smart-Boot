#include "rvio.h"

void rvputc(const char c)
{
  __asm__
    (
     "li a1, 0x10000000\n\t"
     "sb %0, (a1)\n"
     :
     : "r" (c)
     );
}
