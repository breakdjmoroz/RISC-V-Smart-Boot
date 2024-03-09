#include "../hdr/rvio.h"

void test()
{
  rvprints("Hello, %s\n", "World!");
  unsigned int a = 123456789u;
  rvprintu("Number %d\n", a);
}

int main()
{
  test();
  return 0;
}
