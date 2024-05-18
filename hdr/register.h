#ifndef REGISTER
#define REGISTER

#ifdef MTIME_ADDR
#ifdef MTIMECMP_ADDR

#define MIP "mip"
#define MIE "mie"
#define MISA "misa"
#define MEPC "mepc"
#define MTVAL "mtval"
#define MTVEC "mtvec"
#define MCAUSE "mcause"
#define MIMPID "mimpid"
#define MARCHID "marchid"
#define MHARTID "mhartid"
#define MSTATUS "mstatus"
#define MSCRATCH "mscratch"
#define MVENDORID "mvendorid"

extern volatile unsigned long long* MTIME;
extern volatile unsigned long long* MTIMECMP;

#define csr_read(csr) ({                      \
   register unsigned long v;                  \
   __asm__ __volatile__                       \
      (                                       \
       "csrr %0, " csr                        \
       : "=r"(v)                              \
      );                                      \
      v;                                      \
    })

#define csr_write(csr, val) ({                \
    unsigned long v = (unsigned long)(val);   \
    __asm__ __volatile__                      \
      (                                       \
       "csrw " csr ", %0"                     \
       :                                      \
       : "r"(v));                             \
    })

#else
#pragma GCC error "Timer adresses are undefined"
#endif
#else
#pragma GCC error "Timer adresses are undefined"
#endif

#endif
