#ifndef INTERRUPT
#define INTERRUPT

#define UART_INTERRUPT            0x800000000000000B
#define TIMER_INTERRUPT           0x8000000000000007
#define STORE_ACCESS_EXCEPTION    0x0000000000000007

void set_cmp();
void print_mcause();
void print_mepc();
void print_mip();
void print_mie();

void enable_interrupt();
void disable_interrupt();

void __attribute__((interrupt, aligned(16))) handler();

#endif

