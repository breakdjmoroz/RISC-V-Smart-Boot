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

void rvprintnumber(const int number)
{
  char digit = '\0';
  int temp = number;

  while (temp > 0)
  {
    __asm__
      (
       "addi a0, zero, 0xA\n\t"
       "addi t0, zero, 0x0\n\t"
       "lw t1, %1\n\t"
       "jal zero, mod\n"
       "subtract:\n\t"
       "sub t1, t1, a0\n\t"
       "addi t0, t0, 0x1\n"
       "mod:\n\t"
       "slt t2, t1, a0\n\t"
       "beq zero, t2, subtract\n\t"
       "sb t1, %0\n\t"
       "sw t0, %1\n"
       : "+m" (digit)
       : "m" (temp)
       );
    rvputc(digit + 0x30);
  }

}

void rvprintf(const char* fstring, const void* value)
{
  char* cur_c = (char*)fstring;
  while (*cur_c != '\0')
  {
    if (*cur_c == '%')
    {
      ++cur_c;
      switch (*cur_c)
      {
        case 's':
          rvprintstring((char*)value);
          break;
        case 'd':
          rvprintnumber(*(int*)value);
          break;
      }
      ++cur_c;
    }

    rvputc(*cur_c);
    ++cur_c;
  }
}

