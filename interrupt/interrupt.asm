extern _irqHorloge, _irqClavier, _irqDefault, _sysCalls
global _irq0, _irq1, _irq2, _irqLogicielle

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

_irq0:
	SAVE_REGS
    call _irqHorloge
    mov al, 0x20
    out 0x20, al
    RESTORE_REGS
    iret

_irq1:
	SAVE_REGS
    call _irqClavier
    mov al, 0x20
    out 0x20, al
    RESTORE_REGS
    iret

_irq2:
	SAVE_REGS
    call _irqDefault
    mov al, 0x20
    out 0x20, al
    RESTORE_REGS
    iret

_irqLogicielle:
 SAVE_REGS
    push eax
    call _sysCalls
    pop eax
    RESTORE_REGS
    iret
