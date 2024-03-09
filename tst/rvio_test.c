#include "../hdr/rvio_test.h"

void rvio_test()
{
  rv_prints("Hello, %s\n", "World!");
  unsigned int a = 123456789u;
  rv_printu("Number %d\n", a);
}
