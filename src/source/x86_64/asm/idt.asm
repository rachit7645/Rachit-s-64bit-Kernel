global  idt_flush

idt_flush:
    lidt    [rdi]       ; Load the idt and
    sti                 ; Enable Interrupts
    ret