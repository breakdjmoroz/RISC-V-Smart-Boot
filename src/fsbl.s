  .global _start
  .section .text

_start:
  li sp, 0x80100000   #stack base
  call 0x80001000     #main function
