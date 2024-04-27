#include "../hdr/rvio.h"
#include "../hdr/rvmisa.h"


unsigned long long get_misa() {
    unsigned long long misa;
    __asm__ __volatile__ ("csrr %0, misa" : "=r" (misa));
    return misa;
}

void print_misa() {
    unsigned long long misa = get_misa();
    rv_printd("Misa (hexademical): %x\n\r", misa);
    //Size of word

    //rv_printd("SIZE_OF_WORD:: %u\n\r", (misa >> 30) & 0x1);

    // Вывод расшифровки
    rv_printd("A (Atomic extension: %u\n\r", misa & 0x1);
    rv_printd("B (Tentatively reserved for Bit-Manipulation extension): %u\n\r", (misa >> 1) & 0x1);
    rv_printd("C (Compressed extension): %u\n\r", (misa >> 2) & 0x1);
    rv_printd("D (Double-precision floating-point extension): %u\n\r", (misa >> 3) & 0x1);
    rv_printd("E (RV32E base ISA): %u\n\r", (misa >> 4) & 0x1);
    rv_printd("F (Single-precision floating-point extension): %u\n\r", (misa >> 5) & 0x1);
    rv_printd("%u\n\r", (misa >> 6) & 0x1);
    rv_printd("H (Hypervisor extension): %u\n\r", (misa >> 7) & 0x1);
    rv_printd("I (RV32I/64I/128I base ISA):%u\n\r", (misa >> 8) & 0x1);
    rv_printd("%u\n\r", (misa >> 9) & 0x1);
    rv_printd("%u\n\r", (misa >> 10) & 0x1);
    rv_printd("%u\n\r", (misa >> 11) & 0x1);
    rv_printd("M (Integer Multiply/Divide extension: %u", (misa >> 12) & 0x1);
    rv_printd("%u\n\r", (misa >> 13) & 0x1);
    rv_printd("%u\n\r", (misa >> 14) & 0x1);
    rv_printd("%u\n\r", (misa >> 15) & 0x1);
    rv_printd("%u\n\r", (misa >> 16) & 0x1);
    rv_printd("Q (Quad-precision floating-point extension): %u\n\r", (misa >> 17) & 0x1);
    rv_printd("S (Supervisor mode implemented): %u\n\r", (misa >> 18) & 0x1);
    rv_printd("U (User mode implemented): %u\n\r", (misa >> 19) & 0x1);
    rv_printd("%u\n\r", (misa >> 20) & 0x1);
    rv_printd("%u\n\r", (misa >> 21) & 0x1);
    rv_printd("%u\n\r", (misa >> 22) & 0x1);
    rv_printd("X (Non-standard extensions present): %u\n\r", (misa >> 23) & 0x1);
    rv_printd("%u\n\r", (misa >> 24) & 0x1);

    
}


int get_most_significant_bit_number(unsigned long long value) {
    int msb_number = 0; 
    while (value != 0) {
        value >>= 1; // Сдвигаем значение вправо на один бит
        msb_number++; // Увеличиваем номер старшего бита
    }
    return msb_number;
}



int get_misa_xlen() {
    unsigned long long base_width = 0;

    __asm__(
        "csrr a0, misa\n\t"  
        "determine_base_width:\n\t"
        "bltz a0, misa_negative\n\t"  // Переход, если misa отрицательное
        "li a0, 0\n\t"  // Установка базовой ширины в 0 
        "ret\n\t"  
        "misa_negative:\n\t"
        "slli a0, a0, 1\n\t"  // Сдвиг значения misa на один бит влево
        "bltz a0, misa_negative_shifted\n\t"  
        "li a0, 64\n\t"  // Установка базовой ширины в 64
        "ret\n\t"  
        "misa_negative_shifted:\n\t"
        "li a0, 32\n\t"  // Установка базовой ширины в 32
        "ret\n\t"  
    );

    // Возвращаем значение базовой ширины
    return base_width;
}
