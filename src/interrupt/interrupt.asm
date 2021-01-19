extern _irqHorloge, _irqClavier, _irqDefault, _sysCalls
global _irqDef, _irq32, _irq33, _syscall

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

_irq32:
	SAVE_REGS
    call _irqHorloge
    mov al, 0x20
    out 0x20, al
    RESTORE_REGS
    iret

_irq33:
	SAVE_REGS
    call _irqClavier
    mov al, 0x20
    out 0x20, al
    RESTORE_REGS
    iret

_irqDef:
	SAVE_REGS
    call _irqDefault
    mov al, 0x20
    out 0x20, al
    RESTORE_REGS
    iret

_syscall:
	SAVE_REGS
    push eax
    call _sysCalls
    pop eax
    RESTORE_REGS
    iret
