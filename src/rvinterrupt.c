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
  long long mcause = get_mcause();

  mcause = 0x80000000F;

  rv_printd("Mcause: %x\n\r", mcause);
  
  unsigned char interrupt = 0;

  __asm__ (
      "add a0, zero, %1\n\t"
      "srli a1, a0, 0x1\n\t"
      "srai a2, a0, 0x1\n\t"
      "beq a1, a2, end\n\t"
      "addi %0, zero, 0x1\n"

      "end:\n\t"
      : "+r" (interrupt)
      : "r" (mcause)
      );

  rv_printd("interrupt: %u\n\r", interrupt);
  rv_printd("exception code: %u\n\r", mcause & 0x7FFFFFFFFFFFFFFF);
}
