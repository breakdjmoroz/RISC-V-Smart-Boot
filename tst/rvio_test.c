#include "../hdr/rvio_test.h"
#include "../hdr/rvio.h"

void rvio_test()
{
  rv_prints("Hello, %s\n", "World!");
  unsigned int a = 123456789u;
  rv_printd("Number %d\n", a);
}
