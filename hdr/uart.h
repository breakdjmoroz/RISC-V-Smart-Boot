#ifndef UART
#define UART

#include "../hdr/memory.h"

#ifdef UART_BASE

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

#define UART_INTERRUPT_ENABLE(flags) WRITE_BYTE(flags, UART_IER)
#define UART_INTERRUPT_DISABLE(flags) WRITE_BYTE(flags, UART_IER)

#else
#pragma GCC error "UART address is undefined"
#endif

#endif

