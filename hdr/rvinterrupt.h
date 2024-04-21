#ifndef INTERRUPT
#define INTERRUPT

unsigned long long get_mcause();
void print_mcause();
unsigned long long get_mepc();
void print_mepc();
unsigned long long get_mip();
void print_mip();
unsigned long long get_mie();
void print_mie();
#endif

