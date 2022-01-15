.code16
.global _start
.org 0x0

.set OFFSET,  0x1000  # Where wil the kernel be loaded in memory
.set KSIZE,   50      # How many sector we should load
_start:
	jmp begin

.include "PRINT.INC"

begin:
	## init data segment in 0x7c00
	##(data access = ds:offset -> 0x7C0:offset -> 0x7C0*0x10+offset -> 0x7C00+offset -> 0x7C00 at the begining)
	movw $0x07C0, %ax
	movw %ax, %ds
	movw %ax, %es
	movw $0x8000, %ax    #init stack.
	movw %ax, %ss
	movw $0xF000, %sp

	#Write a little msg
	movw $msg_debut, %si
	call puts

	#get the device id where our whole code is located (both bootloader and kernel)
	movb %dl, (boot_drv)

	## Init floppy reader
	xor %ax, %ax
	int $0x13

loadk:
	push %es
	## address read = es:bx -> 0:0x1000 -> 0x1000 ##
	xor %ax, %ax
	movw %ax, %es
	movw $OFFSET, %bx
	################################################
	movb $2, %ah
	movb $KSIZE, %al
	movb $0, %ch
	movb $2, %cl #begin at sector 2 because sector 1 contained the current bootloader
	movb $0, %dh
	movb (boot_drv), %dl
	int $0x13
	pop %es
calc_addr:
	#Process GDT adress : = DS*16 + GDT_ADDR
	xor %eax, %eax  #eax = 0
	xor %ebx, %ebx  #ebx = 0
	movw %ds, %ax   #ax = ds
	movl %eax, %ecx #ecx = ax = ds
	shl $4, %ecx    #ecx <<= 4 <=> ecx *= 16
	movw $gdt, %bx  #ebx = gdt_addr
	addl %ebx, %ecx #ebx += ecx (DS*16)
	#Put the result in the base part of the gdtptr
	movl %ecx, (gdtptr+2)
enter_modep:
	#enter protected mode
	cli
	lgdt (gdtptr)
	movl %cr0, %eax
	or  $1, %ax
	movl %eax, %cr0

	jmp next #Free caches
next:
	#reset data segment
	movw $0x10, %ax
	movw %ax, %ds
	movw %ax, %fs
	movw %ax, %gs
	movw %ax, %es
	movw %ax, %ss
	movl $0x9F000, %esp

	ljmpl $0x8,$0x1000  #reset code segment (here to 8 because it is the corresponding cs entry in the gdt)

/* -------------------------------------------------------------------- */
boot_drv: .byte 0
msg_debut:
	.ascii "Loading kernel..."
/* --------------------------------------------------------------------*/

gdt:
	.byte 0, 0, 0, 0, 0, 0, 0, 0
gdt_cs:
	.byte 0xFF, 0xFF, 0x0, 0x0, 0x0, 0b10011011, 0b11011111, 0x0
gdt_ds:
	.byte 0xFF, 0xFF, 0x0, 0x0, 0x0, 0b10010011, 0b11011111, 0x0
gdtend:
/* --------------------------------------------------------------------*/
gdtptr:
	.word 24 #limit : there is 3 descriptor see above) which are 8 bit long each.
	.long 0  # base

#NOP until 510 (make the bootloader bootable)
.fill (510 + _start - .), 1, 144
.word 0xAA55
