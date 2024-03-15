#include "../hdr/rvio.h"

void rv_putc(const char c)
{
  __asm__
    (
     "li a1, 0x10000000\n\t"
     "sb %0, (a1)\n"
     :
     : "r" (c)
     );
}

void printstring(const char* string)
{
  char* cur_c = (char*)string;
  while (*cur_c != '\0')
  {
    rv_putc(*cur_c);
    ++cur_c;
  }
}

void printu(const unsigned int number, const unsigned int base)
{
  char digit = '\0';
  int temp = number;

  __asm__
    (
     "lw a2, %1\n\t"
     : "+m" (temp)
     );

  __asm__
    (
     "li a7, 0x10000000\n\t"
     "addi a1, zero, 0x0\n\t"

     "getdigits:\n\t"
     "add a0, zero, %0\n\t"
     "addi t0, zero, 0x0\n\t"
     "mv t1, a2\n\t"
     "jal zero, mod\n"

     "subtract:\n\t"
     "sub t1, t1, a0\n\t"
     "addi t0, t0, 0x1\n"

     "mod:\n\t"
     "bge t1, a0, subtract\n\t"
     "addi sp, sp, -0x1\n\t"
     "addi a1, a1, 0x1\n\t"
     "sb t1, (sp)\n\t"
     "mv a2, t0\n\t"
     "bne zero, a2, getdigits\n"

     "putdigits:\n\t"
     "lb t2, (sp)\n\t"

     "addi a6, zero, 0xA\n\t"
     "blt t2, a6, ten\n\t"
     "addi t2, t2, 0x37\n\t"
     "jal zero, store\n"

     "ten: addi t2, t2, 0x30\n\t"

     "store: sb t2, (a7)\n\t"
     "add sp, sp, 0x1\n\t"
     "addi a1, a1, -0x1\n\t"
     "slti t0, a1, 0x1\n\t"
     "beq zero, t0, putdigits\n"
     :
     : "r" (base)
     );

}

void rv_prints(const char* fstring, const char* value)
{
  char* cur_c = (char*)fstring;
  while (*cur_c != '\0')
  {
    if (*cur_c == '%')
    {
      ++cur_c;
      if (*cur_c == 's')
      {
          printstring(value);
      }
      ++cur_c;
    }

    rv_putc(*cur_c);
    ++cur_c;
  }
}

void rv_printd(const char* fstring, const unsigned int value)
{
  char* cur_c = (char*)fstring;
  while (*cur_c != '\0')
  {
    if (*cur_c == '%')
    {
      ++cur_c;
      switch (*cur_c)
      {
        case 'u':
          printu(value, 10u);
          break;
        case 'b':
          printu(value, 2u);
          break;
        case 'x':
          printu(value, 16u);
          break;
      }
      ++cur_c;
    }

    rv_putc(*cur_c);
    ++cur_c;
  }
}

