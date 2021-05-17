#pragma once

#include <stdint.h>

#define ISR0    0
#define ISR1    1
#define ISR2    2
#define ISR3    3
#define ISR4    4
#define ISR5    5
#define ISR6    6
#define ISR7    7
#define ISR8    8
#define ISR9    9
#define ISR10   10
#define ISR11   11
#define ISR12   12
#define ISR13   13
#define ISR14   14
#define ISR15   15
#define ISR16   16
#define ISR17   17
#define ISR18   18
#define ISR19   19
#define ISR20   20
#define ISR21   21
#define ISR22   22
#define ISR23   23
#define ISR24   24
#define ISR25   25
#define ISR26   26
#define ISR27   27
#define ISR28   28
#define ISR29   29
#define ISR30   30
#define ISR31   31

#define IRQ0    32
#define IRQ1    33
#define IRQ2    34
#define IRQ3    35
#define IRQ4    36
#define IRQ5    37
#define IRQ6    38
#define IRQ7    39
#define IRQ8    40
#define IRQ9    41
#define IRQ10   42
#define IRQ11   43
#define IRQ12   44
#define IRQ13   45
#define IRQ14   46
#define IRQ15   47

#define KERNEL_CODE_SEGMENT_OFFSET  0x08
#define INTERRUPT_GATE              0x8E

struct idt_entry {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_attribute;
    uint16_t offset_medium;
    uint32_t offset_high;
    uint32_t zero;
}__attribute__((packed));
typedef struct idt_entry idt_entry_t;

struct idt_ptr {
    uint16_t limit;
    uint64_t offset;
}__attribute__((packed));
typedef struct idt_ptr idt_ptr_t;

void idt_init();

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();