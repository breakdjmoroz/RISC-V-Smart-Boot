#include "../hdr/rvio.h"
#include "../hdr/rvminfo.h"
#include "../hdr/rvminfo_test.h"
#include "../hdr/register.h"

void rvminfo_test(){
  set_mstatus_bit(12,1);
  unsigned long long a;
  a = csr_read(MSTATUS);
  rv_printd("Mstatus (binary): %b\n\r", a);
  //print_mstatus();
  set_mstatus_bit(12,0);
  a = csr_read(MSTATUS);;
  rv_printd("Mstatus (binary): %b after changing bit\n\r", a);
  //print_mstatus(); //Закомментил принты чтоб много место не занимало
}
