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
  unsigned long long mcause = get_mcause();

  rv_printd("Mcause: %x\n\r", mcause);

  unsigned char interrupt = 0;
  unsigned long long exception_code = 0;

  __asm__ (
      "add a0, zero, %1\n\t"
      "srli a1, a0, 0x1\n\t"
      "srai a2, a0, 0x1\n\t"
      "beq a1, a2, exc\n\t"
      "addi %0, zero, 0x1\n"

      "exc:\n\t"
      : "+r" (interrupt)
      : "r" (mcause)
      );

  __asm__(
      "add a0, zero, %1\n\t"
      "slli a2, a0, 0x1\n\t"
      "srli a2, a2, 0x1\n\t"
      "and a2, a2, a0\n\t"
      "add %0, zero, a2\n\t"
      : "+r" (exception_code)
      : "r" (mcause)
      );

  rv_printd("interrupt: %u\n\r", interrupt);
  rv_printd("exception code: %u\n\r", exception_code);
}
