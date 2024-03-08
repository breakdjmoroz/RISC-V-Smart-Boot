#include "../hdr/rvio.h"

int main()
{
  rvprintf("Hello, %s\n", "World!");
  int num = 35;
  rvprintf("Number %d\n", &num);
  rvprintf("Y", "");
  return 0;
}
