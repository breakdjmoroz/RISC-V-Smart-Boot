#include "../hdr/rvinterrupt.h"
#include "../hdr/rvio.h"

unsigned long long get_mip() {
    unsigned long long mip;
    __asm__ __volatile__ ("csrr %0, mepc" : "=r" (mip));
    return mip;
}
unsigned long long get_mie() {
    unsigned long long mie;
    __asm__ __volatile__ ("csrr %0, mepc" : "=r" (mie));
    return mie;
}
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

unsigned long long get_mepc() {
    unsigned long long mepc;
    __asm__ __volatile__ ("csrr %0, mepc" : "=r" (mepc));
    return mepc;
}

void print_mepc(){
  unsigned long long mepc = get_mepc();
  rv_printd("Mepc: %x\n\r", mepc);
}

void print_mip()
{
  unsigned long long mip = get_mip();
  rv_printd("mip: %x\n\r", mip);

  rv_printd("MSIP (Machine Software Interrupt Pending): %u\n\r", (mip & (1 << 0)) != 0);
  rv_printd("MTIP (Machine Timer Interrupt Pending): %u\n\r", (mip & (1 << 7)) != 0);
  rv_printd("MEIP (Machine External Interrupt Pending):  %u\n\r", (mip & (1 << 11)) != 0);
}

void print_mie(){
  unsigned long long mie = get_mie();
  rv_printd("mie: %x\n\r", mie);

  rv_printd("MSIE (Machine Software Interrupt Pending): %u\n\r", (mie & (1 << 3)) != 0);
  rv_printd("MTIE (Machine Timer Interrupt Pending): %u\n\r", (mie & (1 << 7)) != 0);
  rv_printd("MEIE (Machine External Interrupt Pending):  %u\n\r", (mie & (1 << 11)) != 0);
}