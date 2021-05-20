#include "utils.h"
#include "interrupts/pic.h"
#include "keyboard/keyboard.h"
#include <stdint.h>

void irq0_handler() {
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq1_handler() {
    // This is the keyboard IRQ
    // Read scancode from KEYBOARD_DATA_PORT which is 0x60
    uint8_t scancode = inb(KEYBOARD_DATA_PORT);
    // Handle the keyboard
    handle_keyboard(scancode);
	// End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq2_handler() {
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq3_handler() {
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq4_handler() {
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq5_handler() {
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq6_handler() {
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq7_handler() {
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq8_handler() {
    outb(0xA0, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);          
}
 
void irq9_handler() {
    outb(PIC2, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq10_handler() {
    outb(PIC2, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq11_handler() {
    outb(PIC2, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq12_handler() {
    outb(PIC2, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq13_handler() {
    outb(PIC2, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq14_handler() {
    outb(PIC2, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}
 
void irq15_handler() {
    outb(PIC2, PIC_EOI);
    // End of Interrupt
    outb(PIC1, PIC_EOI);
}