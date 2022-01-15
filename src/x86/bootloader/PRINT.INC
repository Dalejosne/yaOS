/*---------------------------------------------------------
; Synopsis: Affiche une chaine de caracteres se terminant par 0x0
; Entree:   DS:SI -> pointe sur la chaine a afficher
;---------------------------------------------------------*/
puts:
	push %ax
	push %bx
.while:
	lodsb         /* ds:si -> al*/
	xor $0, %al     /* fin chaine ? <=> or %al, %al <=> al == 0 ?*/
	jz .end
	movb $0x0E, %ah  /* appel au service 0x0e, int 0x10 du bios*/
	movw $0x07, %bx  /* bx -> attribut, al -> caractere ascii*/
	int $0x10
	jmp .while

.end:
	pop %bx
	pop %ax
	ret

putc:
	push %ax
	push %bx
	lodsb
	movb $0xE, %ah  /* appel au service 0x0e, int 0x10 du bios*/
	movw $0x7, %bx  /* bx -> attribut, al -> caractere ascii*/
	int $0x10
	pop %bx
	pop %ax
	ret

/*Fonction pour afficher un nombre entier sur 16 bits, stocké dans dx*/
putNb:
	push %ax
	push %bx
	push %cx
	movw %dx, %ax
	movw $0, %cx

	.boucleNb:
		inc %cx
		/*On divise ax par 10, en mettant 10 dans bh*/
		movb $10, %bh
		div %bh
		movb %al, %dl
		movb $0, %dh
		movb %ah, %al
		movb $0, %ah
		addb $'0', %al
		push %ax
		movw %dx, %ax
		xor $0, %ax
		jz .boucle2Nb
		jmp .boucleNb

	.boucle2Nb:
		pop %ax
		dec %cx
		movb $0x0E, %ah
		movw $0x07, %bx
		int $0x10
		xor $0, %cx
		jz .stopNb
		jmp .boucle2Nb

	.stopNb:
		pop %cx
		pop %bx
		pop %ax
		ret
