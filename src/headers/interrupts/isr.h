#include <stdint.h>

#define DIVIDE_BY_ZERO_ERROR 	            0x0
#define DEBUG                             0x1
#define NON_MASKABLE_INTERRRUPT           0x2
#define BREAKPOINT                        0x3
#define OVERFLOW                          0x4
#define BOUND_RANGE_EXCEEDED              0x5
#define INVALID_OPCODE                    0x6
#define DEVICE_NOT_AVAILABLE              0x7
#define DOUBLE_FAULT                      0x8
#define INVALID_TSS                       0xA
#define SEGMENT_NOT_PRESENT               0xB
#define STACK_SEGMENT_FAULT               0xC
#define GENERAL_PROTECTION_FAULT          0xD
#define PAGE_FAULT                        0xE
#define x87_FLOATING_POINT_EXCEPTION      0x10
#define ALIGNMENT_CHECK                   0x11
#define MACHINE_CHECK                     0x12
#define SIMD_FLOATING_POINT_EXCEPTION     0x13
#define VIRTUALIZATION_EXCEPTION          0x14
#define SECURITY_EXCEPTION                0x1E 

// A register structure passed by the cpu
struct registers {
   uint32_t ds;                  // Data segment selector
   uint64_t rdi, rsi, rbp, rbx, rdx, rcx, rax; // Pushed by pushall.
   uint32_t int_no, err_code;    // Interrupt number and error code (if applicable)
   uint64_t rip, userrsp; // Pushed by the processor automatically.
   uint32_t cs, eflags, ss;
};
typedef struct registers registers_t;

char* divide_by_zero_error = "DIVIDE_BY_ZERO_ERROR";
char* debug = "DEBUG";
char* non_maskable_interrrupt = "NON_MASKABLE_INTERRRUPT";
char* breakpoint = "BREAKPOINT";
char* overflow = "OVERFLOW";
char* bound_range_exceeded = "BOUND_RANGE_EXCEEDED";
char* invalid_opcode = "INVALID_OPCODE";
char* device_not_available = "DEVICE_NOT_AVAILABLE";
char* double_fault = "DOUBLE_FAULT";
char* invalid_tss = "INVALID_TSS";
char* segment_not_present = "SEGMENT_NOT_PRESENT";
char* stack_segment_fault = "STACK_SEGMENT_FAULT";
char* general_protection_fault = "GENERAL_PROTECTION_FAULT";
char* page_fault = "PAGE_FAULT";
char* x87_floating_point_exception = "x87_FLOATING_POINT_EXCEPTION";
char* alignment_check = "ALIGNMENT_CHECK";
char* machine_check = "MACHINE_CHECK";
char* simd_floating_point_exception = "SIMD_FLOATING_POINT_EXCEPTION";
char* virtualization_exeption = "VIRTUALIZATION_EXCEPTION";
char* security_exception = "SECURITY_EXCEPTION";