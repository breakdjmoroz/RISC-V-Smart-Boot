#ifndef REGISTER
#define REGISTER

#define MIP "mip"
#define MIE "mie"
#define MCAUSE "mcause"
#define MSTATUS "mstatus"


#define csr_read(csr)({ register unsigned long __v; __asm__ __volatile__("csrr %0, " csr : "=r"(__v):: "memory");__v;})


#endif