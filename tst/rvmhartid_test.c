#include "../hdr/rvio.h"
#include "../hdr/rvmhartid.h"
#include "../hdr/rvmhartid_test.h"



void rvmhartid_test() {
    unsigned long long a;
    a = get_mhartid();
    rv_printd("Mhartid: %b\n\r", a);

}