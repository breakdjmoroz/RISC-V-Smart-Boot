#include "../hdr/rvio.h"

void test()
{
  rv_prints("Hello, %s\n\r", "World!");
  unsigned int a = 123456789u;
  rv_printu("Number %d\n\r", a);
}

int main()
{
  test();
  return 0;
}
