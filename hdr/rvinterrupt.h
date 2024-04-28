#ifndef INTERRUPT
#define INTERRUPT

void print_mcause();
void print_mepc();
void print_mip();
void print_mie();

void enable_interrupt();
void disable_interrupt();

#endif

