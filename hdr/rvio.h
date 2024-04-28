#ifndef RVIO
#define RVIO

#define DEC_BASE 10u
#define BIN_BASE 2u
#define HEX_BASE 16u

#define ZERO_CHARACTER 0x30
#define A_CHARACTER 0x37

void rv_putc(const char);
void rv_prints(const char*, const char*);
void rv_printd(const char*, const unsigned long long);

#endif
