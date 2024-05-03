#include "../hdr/rvinterrupt.h"
#include "../hdr/rvio.h"
#include "../hdr/register.h"
#include "../hdr/uart_test.h"
#include "../hdr/uart.h"

void uart_test()
{
  csr_write("pmpcfg0", 0x1F);
  csr_write("pmpaddr0", 0x8FFFFFFF);
  rv_printd("pmpcfg0 is: %x\n\r", csr_read("pmpcfg0"));
  rv_printd("pmpaddr0 is: %x\n\r", csr_read("pmpaddr0"));

  UART_INTERRUPT_ENABLE(RECEIVED_DATA_AVAILIABLE);

  //PLIC ========>
  //uart_irq priority = 7
  WRITE_INT((unsigned int)0x0007, 0x0C000000 + (0x4 * 0xA));
  //uart_irq enable = true
  WRITE_INT((unsigned int)0x0400, 0x0C000000 + (0x2000));
  //<=============

  rv_printd("irq 10 priority is: %x\n\r", 0x1);//*irq_10_addr);

  unsigned char* reg = (unsigned char*)UART_IER;
  rv_printd("ier is: %x\n\r", *reg);

  rv_prints("iterrupt has enabled!\n\r", "");
  print_mie();

  unsigned char* ier = (unsigned char*)UART_IER;
  rv_printd("UART_IER is: %x\n\r", *ier);
  rv_putc('\n');
  rv_putc('\r');
}
