#include "../hdr/rvio.h"
#include "../hdr/rvmhartid.h"


unsigned long long get_mhartid() {
    unsigned long long mhartid;
    __asm__ __volatile__ ("csrr %0, mhartid" : "=r" (mhartid));
    return mhartid;
}

