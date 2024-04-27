#include "../hdr/rvio.h"
#include "../hdr/rvmisa.h"
#include "../hdr/rvmisa_test.h"



void rvmisa_test() {
    unsigned long long a;
    a = get_misa();
    unsigned long long b;
    b = get_misa();
    rv_printd("Misa: %u\n\r", a);
    print_misa();
    
    
    b = get_most_significant_bit_number(b);
    //int value = get_misa_base_width(a);
    rv_printd("STEP: %u\n\r", b);
    unsigned long long xlen = get_misa_xlen();
    rv_printd("XLEN: %u\n\r!!!", xlen);
    return 0;
    
}