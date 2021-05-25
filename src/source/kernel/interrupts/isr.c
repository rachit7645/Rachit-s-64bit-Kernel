#include "interrupts/isr.h"
#include "print.h"

void isr_handler(registers_t regs) {
  print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_RED);
  print_str("Error!!!\nError Code: ");
  print_int(regs.int_no);
  print_char('\n');
}
