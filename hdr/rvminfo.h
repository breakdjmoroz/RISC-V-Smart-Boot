#ifndef RVMINFO
#define RVMINFO

unsigned long long get_mstatus();
void print_mstatus();
void set_mstatus_bit();

unsigned long long get_misa();
void print_misa();
#endif
