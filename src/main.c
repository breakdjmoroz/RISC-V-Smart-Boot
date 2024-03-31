#include "../hdr/rvio.h"
#include "../hdr/tests.h"

void test()
{
  rvio_test();

  unsigned int a = 10;
  unsigned int b = 3;
  division_test(a, b);

  mcause_test();
}

int main()
{
  test();
  return 0;
}
