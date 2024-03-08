#include "../hdr/rvio.h"

int main()
{
  rvprintf("Hello, %s\n", "World!");
  unsigned int a = 123456789u;
  rvprintf("Number %d\n", &a);
  return 0;
}
