#include "../hdr/uart.h"
#include "../hdr/memory.h"
#include "../hdr/rvio.h"
#include "../hdr/rvmath.h"

void rv_putc(const char c)
{

  WRITE_BYTE(c, UART_THR);

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

void printu(const unsigned long long number, const unsigned long long base)
{
  char digit = '\0';
  unsigned long long temp = (unsigned long long)number;

  unsigned int i = 0;

  if (number != 0)
  {
    while (temp > 0)
    {
      digit = i_mod(temp, base);

      __asm__ (
          "addi sp, sp, -0x4\n\t"
          "sw %0, (sp)\n\t"
          : "=r" (digit)
          );

      ++i;
      temp = i_div(temp, base);
    }

    while (i > 0)
    {
      __asm__ (
          "lw %0, (sp)\n\t"
          "addi sp, sp, 0x4\n\t"
          : "+r" (digit)
          );

      --i;

      if (base == HEX_BASE && digit > 10)
      {
        rv_putc(digit + A_CHARACTER);
      }
      else
      {
        rv_putc(digit + ZERO_CHARACTER);
      }
    }
  }
  else
  {
   rv_putc(ZERO_CHARACTER);
  }
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

void rv_printd(const char* fstring, const unsigned long long value)
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
          printu(value, DEC_BASE);
          break;
        case 'b':
          printu(value, BIN_BASE);
          break;
        case 'x':
          printu(value, HEX_BASE);
          break;
      }
      ++cur_c;
    }

    rv_putc(*cur_c);
    ++cur_c;
  }
}

