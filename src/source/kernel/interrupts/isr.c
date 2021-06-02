#include "interrupts/isr.h"
#include "print.h"
#include <stdbool.h>

void isr_handler(registers_t regs) {
	print_clear_panic((uint8_t)(PRINT_COLOR_YELLOW | PRINT_COLOR_RED << 4));
	print_set_color(PRINT_COLOR_LIGHT_GRAY, PRINT_COLOR_RED);
	
  	for(size_t i = 0; i < NUM_COLS + 1; i++)
		print_char((char)219);
	
	print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_RED);
  	print_str("Panic!!!\nError Code: ");
	switch(regs.int_no) {
		case DIVIDE_BY_ZERO_ERROR:
			print_str(divide_by_zero_error);
			print_str(": ");
			break;
		case DEBUG:
			print_str(debug);
			print_str(": ");
			break;
		case NON_MASKABLE_INTERRRUPT:
			print_str(non_maskable_interrrupt);
			print_str(": ");
			break;
		case BREAKPOINT:
			print_str(breakpoint);
			print_str(": ");
			break;
		case OVERFLOW:
			print_str(overflow);
			print_str(": ");
			break;
		case BOUND_RANGE_EXCEEDED:
			print_str(bound_range_exceeded);
			print_str(": ");
			break;
		case INVALID_OPCODE:
			print_str(invalid_opcode);
			print_str(": ");
			break;
		case DEVICE_NOT_AVAILABLE:
			print_str(device_not_available);
			print_str(": ");
			break;
		case DOUBLE_FAULT:
			print_str(double_fault);
			print_str(": ");
			break;
		case INVALID_TSS:
			print_str(invalid_tss);
			print_str(": ");
			break;
		case SEGMENT_NOT_PRESENT:
			print_str(segment_not_present);
			print_str(": ");
			break;
		case STACK_SEGMENT_FAULT:
			print_str(stack_segment_fault);
			print_str(": ");
			break;
		case GENERAL_PROTECTION_FAULT:
			print_str(general_protection_fault);
			print_str(": ");
			break;
		case PAGE_FAULT:
			print_str(page_fault);
			print_str(": ");
			break;
		case x87_FLOATING_POINT_EXCEPTION:
			print_str(x87_floating_point_exception);
			print_str(": ");
			break;
		case ALIGNMENT_CHECK:
			print_str(alignment_check);
			print_str(": ");
			break;
		case MACHINE_CHECK:
			print_str(machine_check);
			print_str(": ");
			break;
		case SIMD_FLOATING_POINT_EXCEPTION:
			print_str(simd_floating_point_exception);
			print_str(": ");
			break;
		case VIRTUALIZATION_EXCEPTION:
			print_str(virtualization_exeption);
			print_str(": ");
			break;
		case SECURITY_EXCEPTION:
			print_str(security_exception);
			print_str(": ");
			break;
	}	  
 	print_int(regs.int_no);
	print_char('\n');
	
	print_set_color(PRINT_COLOR_LIGHT_GRAY, PRINT_COLOR_RED);

	set_col(0);
	set_row(NUM_ROWS - 1);
	for(size_t i = 0; i < NUM_COLS + 1; i++)
		print_char((char)219);

  	while(true)
		asm("hlt\n\t");
}
