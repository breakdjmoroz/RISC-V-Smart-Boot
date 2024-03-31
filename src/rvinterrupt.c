#include "../hdr/rvinterrupt.h"
#include "../hdr/rvio.h"

unsigned long long get_mcause()
{
  unsigned long long mcause;

  __asm__ (
      "csrr %0, mcause\n\t"
      : "+r" (mcause)
      );

  return mcause;
}

void print_mcause()
{
  const unsigned long long mcause = get_mcause();

  rv_printd("Mcause: %u\n\r", mcause);
  
  rv_printd("interrupt: %u\n\r", mcause >> 0x3F);
  rv_printd("exception code: %u\n\r", mcause & 0x7FFFFFFFFFFFFFFF);
}
