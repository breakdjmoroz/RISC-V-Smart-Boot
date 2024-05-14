#include "../hdr/store_access_test.h"
#include "../hdr/rvio.h"

void store_access_test()
{
    // Попытка доступа по невалидному адресу
    unsigned long long* invalid_address = (unsigned long long*)0x8000000000000001; // Невалидный адрес
    *invalid_address = 0xDEADBEEF00000000; // Попытка записи по невалидному адресу
}
