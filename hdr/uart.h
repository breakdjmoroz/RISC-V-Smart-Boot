#ifndef UART
#define UART

#define UART_BASE 0x10000000
#define UART_THR ( UART_BASE + 0x0 )
#define UART_RBR ( UART_BASE + 0x0 )
#define UART_DLL ( UART_BASE + 0x0 )
#define UART_IER ( UART_BASE + 0x1 )
#define UART_DLM ( UART_BASE + 0x1 )
#define UART_IIR ( UART_BASE + 0x2 )
#define UART_FCR ( UART_BASE + 0x2 )
#define UART_LCR ( UART_BASE + 0x3 )
#define UART_MCR ( UART_BASE + 0x4 )
#define UART_LSR ( UART_BASE + 0x5 )
#define UART_MSR ( UART_BASE + 0x6 )
#define UART_SCR ( UART_BASE + 0x7 )

#define RECEIVED_DATA_AVAILIABLE    0x01
#define TRANSMITTER_REGISTER_EMPTY  0x02

void uart_interrupt_enable(const unsigned char flags);
void uart_interrupt_disable(const unsigned char flags);

#endif
