#include "../hdr/tests.h"

void test();

int main()
{
  test();

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

  interrupt_test();
}

