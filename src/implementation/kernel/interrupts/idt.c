#include "interrupts/idt.h"
#include "utils.h"
#include "interrupts/pic.h"
#include <stdint.h>

extern void idt_flush(uint64_t);

static void init_idt();
static void idt_set_gate(uint8_t num, uint64_t base, uint16_t sel, uint8_t flags);
static void init_keyboard();
static void remap_pic();

idt_entry_t idt_entries[256];
idt_ptr_t   idt_pointer;

void idt_init() {
    init_idt();
    init_keyboard();
}

static void init_idt()
{
    idt_pointer.limit = sizeof(idt_entry_t) * 256 - 1;
    idt_pointer.offset  = (uint64_t) &idt_entries;

    memset((uint8_t*)(uintptr_t) &idt_entries, 0, sizeof(idt_entry_t) * 256);

    remap_pic();

    idt_set_gate(ISR0, (uint64_t) isr0, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR1, (uint64_t) isr1, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR2, (uint64_t) isr2, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR3, (uint64_t) isr3, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR4, (uint64_t) isr4, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);  
    idt_set_gate(ISR5, (uint64_t) isr5, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR6, (uint64_t) isr6, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR7, (uint64_t) isr7, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR8, (uint64_t) isr8, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR9, (uint64_t) isr9, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR10, (uint64_t) isr10, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR11, (uint64_t) isr11, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR12, (uint64_t) isr12, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR13, (uint64_t) isr13, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR14, (uint64_t) isr14, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR15, (uint64_t) isr15, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR16, (uint64_t) isr16, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR17, (uint64_t) isr17, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR18, (uint64_t) isr18, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR19, (uint64_t) isr19, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR20, (uint64_t) isr20, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR21, (uint64_t) isr21, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR22, (uint64_t) isr22, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR23, (uint64_t) isr23, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR24, (uint64_t) isr24, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR25, (uint64_t) isr25, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR26, (uint64_t) isr26, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR27, (uint64_t) isr27, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR28, (uint64_t) isr28, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR29, (uint64_t) isr29, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR30, (uint64_t) isr30, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(ISR31, (uint64_t) isr31, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);

    idt_set_gate(IRQ0, (uint64_t) irq0, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ1, (uint64_t) irq1, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ2, (uint64_t) irq2, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ3, (uint64_t) irq3, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ4, (uint64_t) irq4, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ5, (uint64_t) irq5, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ6, (uint64_t) irq6, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ7, (uint64_t) irq7, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ8, (uint64_t) irq8, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ9, (uint64_t) irq9, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ10, (uint64_t) irq10, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ11, (uint64_t) irq11, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ12, (uint64_t) irq12, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ13, (uint64_t) irq13, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ14, (uint64_t) irq14, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);
    idt_set_gate(IRQ15, (uint64_t) irq15, KERNEL_CODE_SEGMENT_OFFSET, INTERRUPT_GATE);

    idt_flush((uint64_t)&idt_pointer);
}

static void idt_set_gate(uint8_t num, uint64_t base, uint16_t sel, uint8_t flags)
{
    idt_entries[num].offset_low = base & 0xFFFF;
    idt_entries[num].offset_medium = (base >> 16) & 0xFFFF;
    idt_entries[num].offset_high = (base >> 32) & 0xFFFFFFFF;

    idt_entries[num].ist = 0;

    idt_entries[num].selector = sel;
    idt_entries[num].zero = 0;
   // We must uncomment the OR below when we get to using user-mode.
   // It sets the interrupt gate's privilege level to 3.
    idt_entries[num].type_attribute  = flags /* | 0x60 */;
}

static void remap_pic() {
    outb(PIC1, 0x11);
    outb(PIC2, 0x11);
    outb(PIC1_DATA, 0x20);
    outb(PIC2_DATA, 40);
    outb(PIC1_DATA, 0x04);
    outb(PIC2_DATA, 0x02);
    outb(PIC1_DATA, 0x01);
    outb(PIC2_DATA, 0x01);
    outb(PIC1_DATA, 0x0);
    outb(PIC2_DATA, 0x0);
}

static void init_keyboard() {
    outb(PIC1_DATA,0xFD);
    outb(PIC2_DATA,0xFF);
}