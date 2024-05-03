#include "../hdr/rvio.h"
#include "../hdr/tests.h"

void main_loop();
void end_main();
void test();

int main()
{
  test();

  main_loop();

  end_main();

  return 0;
}

void test()
{
  rvio_test();

  unsigned int a = 10;
  unsigned int b = 3;
  division_test(a, b);

  mcause_test();
  
  rvminfo_test();
  mepc_test();
  rvmisa_test();
  rvmhartid_test();
  mip_enable_test();
  uart_test();
}

void end_main()
{  
  disable_interrupt();
  rv_prints("The end!\n\r", "");
  __asm__("end:\n\t");
  __asm__("jal zero, end");
}

void main_loop()
{
  __asm__("loop:\n\t");
  __asm__("jal zero, loop");
}
