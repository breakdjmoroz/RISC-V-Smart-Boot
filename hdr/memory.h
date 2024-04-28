#ifndef MEMORY
#define MEMORY

#define WRITE_TO_MEMORY(val, addr) ({                             \
    unsigned char* const ptr = (unsigned char* const)addr;        \
    unsigned char value = (unsigned char)val;                     \
    *ptr = value;                                                 \
    })

#define READ_FROM_MEMORY(addr) ({                                 \
    const unsigned char* const ptr = (unsigned char* const)addr;  \
    unsigned char value = *(unsigned char)ptr;                    \
    value;                                                        \
    })

#endif

