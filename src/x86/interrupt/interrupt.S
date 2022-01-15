.global _irqDef, _irq32, _irq33, _syscall

.macro  SAVE_REGS
		pushal
		push %ds
		push %es
		push %fs
		push %gs
		push %ebx
		movw $0x10, %bx
		movw %bx,%ds
		pop %ebx
.endm

.macro  RESTORE_REGS
		pop %gs
		pop %fs
		pop %es
		pop %ds
		popal
.endm

_irq32:
	SAVE_REGS
	call _irqHorloge
	movb $0x20, %al
	out %al, $0x20
	RESTORE_REGS
	iret

_irq33:
	SAVE_REGS
	call _irqClavier
	movb $0x20, %al
	out %al, $0x20
	RESTORE_REGS
	iret

_irqDef:
	SAVE_REGS
	call _irqDefault
	movb $0x20, %al
	out %al, $0x20
	RESTORE_REGS
	iret

_syscall:
	SAVE_REGS
	push %eax
	call _sysCalls
	pop %eax
	RESTORE_REGS
	iret
