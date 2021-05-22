; ISR macros
%macro ISR_NOERRCODE 1  
  global isr%1

  isr%1:
    cli
    push    byte 0
    push    byte %1
    jmp     isr_common_stub
%endmacro

%macro ISR_ERRCODE 1
  global isr%1

  isr%1:
    cli
    push    byte %1
    jmp     isr_common_stub
%endmacro

; Popa and pusha macros
%macro pushall 0
  push    rax
  push    rbx
  push    rcx
  push    rdx
  push    rsi
  push    rdi
  push    rbp
%endmacro

%macro popall 0
  pop     rbp
  pop     rdi
  pop     rsi
  pop     rdx
  pop     rcx
  pop     rbx
  pop     rax
%endmacro

; ISRs
ISR_NOERRCODE   0
ISR_NOERRCODE   1
ISR_NOERRCODE   2
ISR_NOERRCODE   3
ISR_NOERRCODE   4
ISR_NOERRCODE   5
ISR_NOERRCODE   6
ISR_NOERRCODE   7
ISR_ERRCODE     8
ISR_NOERRCODE   9
ISR_ERRCODE     10
ISR_ERRCODE     11
ISR_ERRCODE     12
ISR_ERRCODE     13
ISR_ERRCODE     14
ISR_NOERRCODE   15
ISR_NOERRCODE   16
ISR_ERRCODE     17
ISR_NOERRCODE   18
ISR_NOERRCODE   19
ISR_NOERRCODE   20
ISR_ERRCODE     21
ISR_NOERRCODE   22
ISR_NOERRCODE   23
ISR_NOERRCODE   24
ISR_NOERRCODE   25
ISR_NOERRCODE   26
ISR_NOERRCODE   27
ISR_NOERRCODE   28
ISR_NOERRCODE   29
ISR_NOERRCODE   30
ISR_NOERRCODE   31

global  irq0
global  irq1
global  irq2
global  irq3
global  irq4
global  irq5
global  irq6
global  irq7
global  irq8
global  irq9
global  irq10
global  irq11
global  irq12
global  irq13
global  irq14
global  irq15

extern  irq0_handler
extern  irq1_handler
extern  irq2_handler
extern  irq3_handler
extern  irq4_handler
extern  irq5_handler
extern  irq6_handler
extern  irq7_handler
extern  irq8_handler
extern  irq9_handler
extern  irq10_handler
extern  irq11_handler
extern  irq12_handler
extern  irq13_handler
extern  irq14_handler
extern  irq15_handler

extern  isr_handler

; Common ISR handler
isr_common_stub:
    pushall

    mov     ax, ds
    push    rax

    mov     ax, 0x08
    mov     ds, ax
    mov     es, ax
    mov     fs, ax
    mov     gs, ax 

    call    isr_handler

    pop     rax    
    mov     ds, ax
    mov     es, ax
    mov     fs, ax
    mov     gs, ax

    popall
    add     rsp, 8
    sti
    iretq

; Irq handlers
irq0:
  pushall
  call  irq0_handler
  popall
  iretq
 
irq1:
  pushall
  call  irq1_handler
  popall
  iretq
 
irq2:
  pushall
  call  irq2_handler
  popall
  iretq
 
irq3:
  pushall
  call  irq3_handler
  popall
  iretq
 
irq4:
  pushall
  call  irq4_handler
  popall
  iretq
 
irq5:
  pushall
  call  irq5_handler
  popall
  iretq
 
irq6:
  pushall
  call  irq6_handler
  popall
  iretq
 
irq7:
  pushall
  call  irq7_handler
  popall
  iretq
 
irq8:
  pushall
  call  irq8_handler
  popall
  iretq
 
irq9:
  pushall
  call  irq9_handler
  popall
  iretq
 
irq10:
  pushall
  call  irq10_handler
  popall
  iretq
 
irq11:
  pushall
  call  irq11_handler
  popall
  iretq
 
irq12:
  pushall
  call  irq12_handler
  popall
  iretq
 
irq13:
  pushall
  call  irq13_handler
  popall
  iretq
 
irq14:
  pushall
  call  irq14_handler
  popall
  iretq
 
irq15:
  pushall
  call  irq15_handler
  popall
  iretq