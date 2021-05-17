#include <stdint.h>

struct registers
{
   uint32_t ds;                  // Data segment selector
   uint64_t rdi, rsi, rbp, rbx, rdx, rcx, rax; // Pushed by pushall.
   uint64_t int_no, err_code;    // Interrupt number and error code (if applicable)
   uint64_t rip, userrsp; // Pushed by the processor automatically.
   uint32_t cs, eflags, ss;
};
typedef struct registers registers_t;