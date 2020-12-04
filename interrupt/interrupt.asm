<<<<<<< HEAD
extern _irqHorloge, _irqClavier, _irqDefault, _sysCalls
<<<<<<< HEAD
=======
extern _irqHorloge, _irqClavier, _irqDefault, _sysCalls, putchar
>>>>>>> master
global _irq0, _irq1, _irq2, _irqLogicielle
=======
global _irqDef, _irq32, _irq33, _irqLogicielle
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e

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

_irqLogicielle:
<<<<<<< HEAD
<<<<<<< HEAD
 SAVE_REGS
=======
	SAVE_REGS
>>>>>>> master
=======
	SAVE_REGS
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e
    push eax
    call _sysCalls
    pop eax
    RESTORE_REGS
    iret
