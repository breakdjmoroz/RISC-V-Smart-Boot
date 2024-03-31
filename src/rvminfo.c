#include "../hdr/rvio.h"
#include "../hdr/rvminfo.h"

unsigned long long get_mstatus() {
    unsigned long long mstatus;
    asm volatile ("csrr %0, mstatus" : "=r" (mstatus));
    return mstatus;
}

void print_mstatus() {
    unsigned long long mstatus = get_mstatus();
    rv_printd("Mstatus (hexademical): %x\n", mstatus);

    // Вывод расшифровки
    rv_printd("uie (User Interrupt Enable): %u\n", mstatus & 0x1);
    rv_printd("sie (Supervisor Interrupt Enable): %u\n", (mstatus >> 1) & 0x1);
    rv_printd("mie (Machine Interrupt Enable): %u\n", (mstatus >> 3) & 0x1);
    rv_printd("upie (User Previous Interrupt Enable): %u\n", (mstatus >> 4) & 0x1);
    rv_printd("spie (Supervisor Previous Interrupt Enable): %u\n", (mstatus >> 5) & 0x1);
    rv_printd("mpie (Machine Previous Interrupt Enable): %u\n", (mstatus >> 7) & 0x1);
    rv_printd("spp (Supervisor Previous Privilege): %u\n", (mstatus >> 8) & 0x1);
    rv_printd("mpp (Machine Previous Privilege): %u", (mstatus >> 12) & 0x1);
    rv_printd("%u\n", (mstatus >> 11) & 0x1);
    rv_printd("fs (Floating-Point Status): %u", (mstatus >> 14) & 0x1);
    rv_printd("%u\n", (mstatus >> 13) & 0x1);
    rv_printd("xs (Extension Status): %u", (mstatus >> 16) & 0x1);
    rv_printd("%u\n", (mstatus >> 15) & 0x1);
    rv_printd("mprv (Modify privelege): %u\n", (mstatus >> 17) & 0x1);
    rv_printd("sum (permit Supervisor User Memory access): %u\n", (mstatus >> 18) & 0x1);
    rv_printd("mxr (Make Executable Readable): %u\n", (mstatus >> 19) & 0x1);
    rv_printd("tvm (Trap Virtual Memory): %u\n", (mstatus >> 20) & 0x1);
    rv_printd("tw (Timeout Wait): %u\n", (mstatus >> 21) & 0x1);
    rv_printd("tsr (Trap Sret): %u\n", (mstatus >> 22) & 0x1);
    rv_printd("uxl (User Extension Level): %u", (mstatus >> 33) & 0x1);
    rv_printd("%u\n", (mstatus >> 32) & 0x1);
    rv_printd("sxl (Supervisor Extension Level): %u", (mstatus >> 35) & 0x1);
    rv_printd("%u\n", (mstatus >> 34) & 0x1);
    rv_printd("sd (Synchronous Device): %u\n", (mstatus >> 63) & 0x1);
}

void set_mstatus_bit(int bit_number, int value) {
    unsigned long long mask = 1u << bit_number;
    unsigned long long mstatus_value = get_mstatus();
    // Установка или сброс заданного бита в зависимости от значения
    if (value)
        mstatus_value |= mask;  // Установка бита
    else
        mstatus_value &= ~mask; // Сброс бита
    // Запись обновленного значения регистра mstatus
    asm volatile ("csrw mstatus, %0" : : "r"(mstatus_value));
}
