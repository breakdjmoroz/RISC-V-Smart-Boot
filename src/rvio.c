#include "../hdr/rvio.h"

void rvputc(const char c)
{
  __asm__
    (
     "li a1, 0x10000000\n\t"
     "sb %0, (a1)\n"
     :
     : "r" (c)
     );
}

void rvprintstring(const char* string)
{
  char* cur_c = (char*)string;
  while (*cur_c != '\0')
  {
    rvputc(*cur_c);
    ++cur_c;
  }
}

void rvprintf(const char* fstring, const char* value)
{
  char* cur_c = (char*)fstring;
  while (*cur_c != '\0')
  {
    if (*cur_c == '%')
    {
      ++cur_c;
      if(*cur_c == 's')
      {
        rvprintstring(value);
      }
      ++cur_c;
    }

    rvputc(*cur_c);
    ++cur_c;
  }
}
