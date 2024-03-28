#include "../hdr/rvio_test.h"
#include "../hdr/rvio.h"

void rvio_test()
{
  rv_prints("Hello, %s\n\r", "World!");
  unsigned int a = 45u;
  rv_printd("Number %u\n\r", a);
  rv_printd("Number %b\n\r", a);
  rv_printd("Number %x\n\r", a);
}
