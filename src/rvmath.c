#include "../hdr/rvmath.h"

unsigned long long div_dec(const unsigned long long number)  
{
  unsigned long long temp = (number >> 1) + (number >> 2);
  
  temp += temp >> 4;
  temp += temp >> 8;
  temp += temp >> 16;
  temp += temp >> 32;

  return temp >> 3;
}

unsigned long long i_div(const unsigned long long a, const unsigned long long b)  
{
  unsigned long long result = 0;

  switch(b)
  {
    case DEC_BASE:
      result = div_dec(a);
      break;
    case BIN_BASE:
      result = a >> 1;
      break;
    case HEX_BASE:
      result = a >> 4;
      break;
    default:
      rv_prints("This base is unsupported.\n\r", "");
  }


  return result;
}

unsigned long long i_mod(const unsigned long long a,const unsigned long long b)
{
  unsigned long long result = 0;

  switch(b)
  {
    case DEC_BASE:
      unsigned long long temp = div_dec(a);
      temp = a - ((temp << 3) + (temp << 1));
      result = (temp > 9)? temp - DEC_BASE : temp;
      break;
    case BIN_BASE:
      result = a & 1;
      break;
    case HEX_BASE:
      result = a & 15;
      break;
    default:
      rv_prints("This base is unsupported.\n\r", "");
  }

  return result;
}
