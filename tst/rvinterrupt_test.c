#include "../hdr/rvinterrupt_test.h"
#include "../hdr/rvinterrupt.h"
#include "../hdr/uart_test.h"

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

void interrupt_test()
{
  uart_test();
}
