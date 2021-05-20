#include "print.h"
#include "interrupts/idt.h"
#include <stdbool.h>

void kernel_main() {
    
    // Intialise interrupts
    idt_init();

    print_clear();
    print_set_color(PRINT_COLOR_LIGHT_CYAN, PRINT_COLOR_BLACK);
    print_str("My 64 bit Kernel\nVersion Beta 0.1\nMade by Rachit Khandelwal\nMade using x86 Assembly, x86_64 Assembly and the C Programming Language\nTools used:\nIDE: Visual Studio Code\nDevelopment Tools: Docker Desktop with a GCC x86_64 cross compiler, Make, NASM \nAssembly Compiler, Xorisso, and GRUB");
    print_set_color(PRINT_COLOR_WHITE , PRINT_COLOR_BLACK);
    print_str("\n\nOSBETA>");

    // Halt the system forever so that interrrupts do not crash the kernel
    while(true)
    asm("hlt\n\t");
    
}