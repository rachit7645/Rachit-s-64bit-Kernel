#include "utils.h"
#include "interrupts/pic.h"
#include "keyboard/keyboard.h"
#include <stdint.h>

void irq0_handler() {
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq1_handler() {
    uint8_t scancode = inb(KEYBOARD_DATA_PORT);
    handle_keyboard(scancode);
	outb(PIC1, PIC_EOI); //EOI
}
 
void irq2_handler() {
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq3_handler() {
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq4_handler() {
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq5_handler() {
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq6_handler() {
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq7_handler() {
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq8_handler() {
    outb(0xA0, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI          
}
 
void irq9_handler() {
    outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq10_handler() {
    outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq11_handler() {
    outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq12_handler() {
    outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq13_handler() {
    outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq14_handler() {
    outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI
}
 
void irq15_handler() {
    outb(PIC2, PIC_EOI);
    outb(PIC1, PIC_EOI); //EOI
}