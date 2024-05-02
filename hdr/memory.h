#ifndef MEMORY
#define MEMORY

#define WRITE_BYTE(val, addr) ({                                  \
    volatile unsigned char* const ptr = (volatile unsigned char* const)(addr);                              \
    unsigned char value = (unsigned char)val;                     \
    *ptr = value;                                                 \
    })

#define WRITE_INT(val, addr) ({                                   \
    volatile unsigned int* const ptr = (volatile unsigned int* const)(addr);                               \
    unsigned int value = (unsigned int)val;                       \
    *ptr = value;                                                 \
    })

#define READ_BYTE(addr) ({                                        \
    const volatile unsigned char* const ptr = (const volatile unsigned char* const)(addr);                        \
    const unsigned char value = *ptr;                    \
    value;                                                        \
    })

#define READ_INT(addr) ({                                         \
    const volatile unsigned int* const ptr = (const volatile unsigned int* const)(addr);                         \
    const unsigned int value = *((unsigned int)ptr);                      \
    value;                                                        \
    })

#endif

