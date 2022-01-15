.global _irq0, _irq1, _irq2, _irq3, _irq4, _irq6, _irq7, _irq10, _irq11, _irq12, _irq13, _irq14, _irq16, _irq17, _irq18, _irq19, _irq20, _irq30, _irqExcDefault

.macro  SAVE_REGS
        pushal
        push %ds
        push %es
        push %fs
        push %gs
        push %ebx
        mov $0x10, %bx
        mov %bx,%ds
        pop %ebx
.endm

.macro  RESTORE_REGS
        pop %gs
        pop %fs
        pop %es
        pop %ds
        popal
.endm

_irqExcDefault:
	SAVE_REGS
    call _defaultException
    RESTORE_REGS
    addl $4, %esp
    iret

_irq0:
	SAVE_REGS
    call _divideByZeroExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq1:
	SAVE_REGS
    call _debugExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq2:
	SAVE_REGS
    call _nonMaskIntExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq3:
	SAVE_REGS
    call _bpExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq4:
	SAVE_REGS
    call _overflowExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq6:
	SAVE_REGS
    call _invalidOpcodeExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq7:
	SAVE_REGS
    call _nmExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq10:
	SAVE_REGS
    call _tsExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq11:
	SAVE_REGS
    call _npExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq12:
	SAVE_REGS
    call _ssExcept
    RESTORE_REGS
    addl $4, %esp
    iret
    
_irq13:
	SAVE_REGS
    call _gpExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq14:
	SAVE_REGS
    call _pageExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq16:
	SAVE_REGS
    call _mfExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq17:
	SAVE_REGS
    call _acExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq18:
	SAVE_REGS
    call _mcExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq19:
	SAVE_REGS
    call _xmExcept
    RESTORE_REGS
    addl $4, %esp
    iret
    
_irq20:
	SAVE_REGS
    call _veExcept
    RESTORE_REGS
    addl $4, %esp
    iret

_irq30:
	SAVE_REGS
    call _sxExcept
    RESTORE_REGS
    addl $4, %esp
    iret
