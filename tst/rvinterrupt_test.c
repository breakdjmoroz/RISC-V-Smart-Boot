#include "../hdr/rvinterrupt_test.h"
#include "../hdr/rvinterrupt.h"

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
