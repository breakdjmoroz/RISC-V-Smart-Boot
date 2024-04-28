#include "../hdr/interrupt.h"
#include "../hdr/rvio.h"
#include "../hdr/uart_test.h"
#include "../hdr/uart.h"

void uart_test()
{
  enable_interrupt();
  print_mie;

  disable_interrupt();
  print_mie;
}
