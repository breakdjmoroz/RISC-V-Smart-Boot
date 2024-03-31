#include "../hdr/rvmath_test.h"
#include "../hdr/rvmath.h"
#include "../hdr/rvio.h"

void division_test(const unsigned int a, const unsigned int b)
{
  rv_printd("Number a: %u, b: ", a);
  rv_printd("%u\n\r", b);
  rv_printd("Mod: %u\n\r", i_mod(a, b));
  rv_printd("Div: %u\n\r", i_div(a, b));
  rv_prints("%s", "End\n\r");
}
