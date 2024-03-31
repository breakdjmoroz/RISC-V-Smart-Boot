#include "../hdr/rvinterrupt.h"
#include "../hdr/rvio.h"

unsigned long long get_mcause()
{
  unsigned long long mcause;

  __asm__ (
      "csrr %0, mcause"
      : "+r" (mcause)
      );

  return mcause;
}

void print_mcause()
{
  const unsigned long long mcause = get_mcause();
  rv_printd("Mcause: %x\n\r", mcause);
}
