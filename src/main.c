#include "../hdr/rvio.h"

void test()
{
  rv_prints("Hello, %s\n", "World!");
  unsigned int a = 123456789u;
  rv_printu("Number %d\n", a);
}

int main()
{
  test();
  return 0;
}
