extern irq_horloge, irq_clavier, default_irq
global _irq_0, _irq_1, _irq_2

%macro  SAVE_REGS 0
        pushad 
        push ds
        push es
        push fs
        push gs 
        push ebx
        mov bx,0x10
        mov ds,bx
        pop ebx
%endmacro

%macro  RESTORE_REGS 0
        pop gs
        pop fs
        pop es
        pop ds
        popad
%endmacro

_irq_0:
	SAVE_REGS
    call irq_horloge
    mov al, 0x20
    out 0x20, al
    RESTORE_REGS
    iret

_irq_1:
    call irq_clavier
    mov al, 0x20
    out 0x20, al
    iret

_irq_2:
    call default_irq
    mov al, 0x20
    out 0x20, al
    iret
