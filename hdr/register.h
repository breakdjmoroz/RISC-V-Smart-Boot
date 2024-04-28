#ifndef REGISTER
#define REGISTER

#define MIP "mip"
#define MIE "mie"
#define MISA "misa"
#define MTVAL "mtval"
#define MTVEC "mtvec"
#define MCAUSE "mcause"
#define MIMPID "mimpid"
#define MARCHID "marchid"
#define MHARTID "mhartid"
#define MSTATUS "mstatus"
#define MSCRATCH "mscratch"
#define MVENDORID "mvendorid"

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

/*dont work normal*/
/*#define csr_modify(csr, set_bit, bitpos)                                                            \
    ({                                                                                              \
        unsigned long __mask = (1UL << (bitpos));                                                   \
        unsigned long __read_val;                                                                   \
        if (set_bit) {                                                                              \
            __asm volatile("csrs " csr ", %0":: "r"(mask): "memory");   \
        } else {                                                                                    \
            __asm volatile("csrc " csr ", %0":: "r"(__mask): "memory");    \
        }                                                                                                \           
    })*/


#endif
