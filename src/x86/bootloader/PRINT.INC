;---------------------------------------------------------
; Synopsis: Affiche une chaine de caracteres se terminant par 0x0
; Entree:   DS:SI -> pointe sur la chaine a afficher
;---------------------------------------------------------
puts:
    push ax
    push bx
.while:
    lodsb         ; ds:si -> al
    xor al, 0     ; fin chaine ?
    jz .end
    mov ah, 0x0E  ; appel au service 0x0e, int 0x10 du bios
    mov bx, 0x07  ; bx -> attribut, al -> caractere ascii
    int 0x10
    jmp .while

.end:
    pop bx
    pop ax
    ret
    
putc:
	push ax
	push bx
	lodsb
	mov ah, 0x0E  ; appel au service 0x0e, int 0x10 du bios
    mov bx, 0x07  ; bx -> attribut, al -> caractere ascii
    int 0x10
    pop bx
    pop ax
    ret

;Fonction pour afficher un nombre entier sur 16 bits, stocké dans dx    
putNb:
	push ax
	push bx
	push cx
	mov ax, dx
	mov cx, 0
	
	.boucleNb:
		inc cx
		;On divise ax par 10, en mettant 10 dans bh
		mov bh, 10
		div bh
		mov dl, al
		mov dh, 0
		mov al, ah
		mov ah, 0
		add al, '0'
		push ax
		mov ax, dx
		xor ax, 0
		jz .boucle2Nb
		jmp .boucleNb
	
	.boucle2Nb:
		pop ax
		dec cx
		mov ah, 0x0E
		mov bx, 0x07
		int 0x10
		xor cx, 0
		jz .stopNb
		jmp .boucle2Nb

	.stopNb:
		pop cx
		pop bx
		pop ax
		ret
