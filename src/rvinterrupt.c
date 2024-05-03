#include "../hdr/rvinterrupt.h"
#include "../hdr/rvio.h"
#include "../hdr/uart.h"
#include "../hdr/memory.h"
#include "../hdr/register.h"

void print_mcause()
{
  unsigned long long mcause = csr_read(MCAUSE);

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
  //unsigned long long mip = get_mip();

  unsigned long long mip = csr_read(MIP);
  rv_printd("mip: %x\n\r", mip);

  rv_printd("MSIP (Machine Software Interrupt Pending): %u\n\r", (mip & (1 << 0)) != 0);
  rv_printd("MTIP (Machine Timer Interrupt Pending):    %u\n\r", (mip & (1 << 7)) != 0);
  rv_printd("MEIP (Machine External Interrupt Pending): %u\n\r", (mip & (1 << 11)) != 0);
}

void print_mie(){
  unsigned long long mie = csr_read(MIE);
  rv_printd("mie: %x\n\r", mie);

  rv_printd("MSIE (Machine Software Interrupt Pending): %u\n\r", (mie & (1 << 3)) != 0);
  rv_printd("MTIE (Machine Timer Interrupt Pending):    %u\n\r", (mie & (1 << 7)) != 0);
  rv_printd("MEIE (Machine External Interrupt Pending): %u\n\r", (mie & (1 << 11)) != 0);
}

void enable_interrupt()
{
  const int mie = csr_read(MIE);
  csr_write(MIE, 0x0);

  csr_write(MTVEC, (void*)(handler));

  csr_write(MSTATUS, csr_read(MSTATUS) | (1u << 3) | (1u << 1));

  csr_write(MIE, mie | (1u << 11) | (1u << 3) | (1u << 1) | (1u << 12));
}

void disable_interrupt()
{
  csr_write(MTVEC, 0x0);

  csr_write(MSTATUS, csr_read(MSTATUS) & !(1u << 3u) & !(1u << 1));

  csr_write(MIE, csr_read(MIE) & !(1u << 3u) & !(1u << 11u) & !(1u << 1) & !(1u << 12));
}

void __attribute__((interrupt, aligned(16))) handler()
{
  disable_interrupt();

  unsigned long long mcause = csr_read(MCAUSE);

  if ((mcause & 0x8000000000000000) && (mcause & 0xB))
  {
    //UART Interrupt
    unsigned char ch = READ_BYTE(UART_RBR);

    if (ch == 0x1B)
    {
      enable_interrupt();
      //TODO: change "pending" to "timer_test"
      __asm__ ("jal zero, pending");
    }

    rv_putc(ch);

  }
  else if ((mcause & 0x8000000000000000) && (mcause & 0x7))
  {
    //Timer interrupt
  }
  /*else if ()
  {
    //Illegal address
  }*/
  else
  {
    rv_prints("Default interrupt handler\n\r", "");
  }

  enable_interrupt();

  __asm__("jal zero, pending");
}
