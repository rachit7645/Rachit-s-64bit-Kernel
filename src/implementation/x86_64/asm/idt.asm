global  idt_flush

idt_flush:
    lidt    [rdi]
    sti
    ret