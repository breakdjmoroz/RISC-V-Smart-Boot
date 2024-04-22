#include "../hdr/rvio.h"
#include "../hdr/rvminfo.h"
#include "../hdr/rvinterrupt.h"
#include "../hdr/rvinterrupt.h"
#include "../hdr/register.h"


void print_mstatus() {
    unsigned long long mstatus = csr_read(MSTATUS);
    rv_printd("Mstatus (hexademical): %x\n\r", mstatus);

    // Вывод расшифровки
    rv_printd("uie (User Interrupt Enable): %u\n\r", mstatus & 0x1);
    rv_printd("sie (Supervisor Interrupt Enable): %u\n\r", (mstatus >> 1) & 0x1);
    rv_printd("mie (Machine Interrupt Enable): %u\n\r", (mstatus >> 3) & 0x1);
    rv_printd("upie (User Previous Interrupt Enable): %u\n\r", (mstatus >> 4) & 0x1);
    rv_printd("spie (Supervisor Previous Interrupt Enable): %u\n\r", (mstatus >> 5) & 0x1);
    rv_printd("mpie (Machine Previous Interrupt Enable): %u\n\r", (mstatus >> 7) & 0x1);
    rv_printd("spp (Supervisor Previous Privilege): %u\n\r", (mstatus >> 8) & 0x1);
    rv_printd("mpp (Machine Previous Privilege): %u", (mstatus >> 12) & 0x1);
    rv_printd("%u\n\r", (mstatus >> 11) & 0x1);
    rv_printd("fs (Floating-Point Status): %u", (mstatus >> 14) & 0x1);
    rv_printd("%u\n\r", (mstatus >> 13) & 0x1);
    rv_printd("xs (Extension Status): %u", (mstatus >> 16) & 0x1);
    rv_printd("%u\n\r", (mstatus >> 15) & 0x1);
    rv_printd("mprv (Modify privelege): %u\n\r", (mstatus >> 17) & 0x1);
    rv_printd("sum (permit Supervisor User Memory access): %u\n\r", (mstatus >> 18) & 0x1);
    rv_printd("mxr (Make Executable Readable): %u\n\r", (mstatus >> 19) & 0x1);
    rv_printd("tvm (Trap Virtual Memory): %u\n\r", (mstatus >> 20) & 0x1);
    rv_printd("tw (Timeout Wait): %u\n\r", (mstatus >> 21) & 0x1);
    rv_printd("tsr (Trap Sret): %u\n\r", (mstatus >> 22) & 0x1);
    rv_printd("uxl (User Extension Level): %u", (mstatus >> 33) & 0x1);
    rv_printd("%u\n\r", (mstatus >> 32) & 0x1);
    rv_printd("sxl (Supervisor Extension Level): %u", (mstatus >> 35) & 0x1);
    rv_printd("%u\n\r", (mstatus >> 34) & 0x1);
    rv_printd("sd (Synchronous Device): %u\n\r", (mstatus >> 63) & 0x1);
}

void set_mstatus_bit(int bit_number, int value) {
    unsigned long long mask = 1u << bit_number;
    unsigned long long mstatus_value = csr_read(MSTATUS);
    // Установка или сброс заданного бита в зависимости от значения
    if (value)
        mstatus_value |= mask;  // Установка бита
    else
        mstatus_value &= ~mask; // Сброс бита
    // Запись обновленного значения регистра mstatus
    __asm__ __volatile__ ("csrw mstatus, %0" : : "r"(mstatus_value));
}
