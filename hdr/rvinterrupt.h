#ifndef INTERRUPT
#define INTERRUPT

void set_cmp();
void print_mcause();
void print_mepc();
void print_mip();
void print_mie();

void enable_interrupt();
void disable_interrupt();

void __attribute__((interrupt, aligned(16))) handler();

#endif

