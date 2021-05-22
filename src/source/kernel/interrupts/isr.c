#include "interrupts/isr.h"
#include "print.h"

void isr_handler(registers_t regs) {
  print_str("\nError!!!\nError code: ");
  print_char((char) regs.int_no);
} 