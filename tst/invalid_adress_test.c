#include "../hdr/rvinterrupt.h"
#include "../hdr/register.h"

invalid_adress_test() {
    // Установка обработчика прерывания (исключения)
    asm volatile ("csrw mtvec, %0" :: "r"(&exception_handler));

    // Попытка доступа по невалидному адресу
    uint64_t* invalid_address = (uint32_t*)0x8000000000000001; // Невалидный адрес
    *invalid_address = 0xDEADBEEF00000000; // Попытка записи по невалидному адресу

    // Продолжение выполнения программы после попытки доступа по невалидному адресу (если обработчик не вызывает exit)
    printf("Execution continues after illegal address access\n");

    return 0;
}