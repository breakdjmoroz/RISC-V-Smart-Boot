#include "../hdr/rvinterrupt_test.h"
#include "../hdr/rvinterrupt.h"
#include "../hdr/uart_test.h"
//#include "../hdr/timer_test.h"
//#include "../hdr/address_exception_test.h"

void mcause_test()
{
  print_mcause();
}

void mepc_test()
{
  print_mepc();
}
void mip_enable_test()
{
  print_mip();
  print_mie();
}

void pending()
{
  __asm__("wfi\n\t");
}

void interrupt_test()
{
  enable_interrupt();

  uart_test();
  //timer_test();
  //address_exception_test();

  pending();

  disable_interrupt();
}
