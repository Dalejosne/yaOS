#include "interrupt.h"
#include "../lib/stdlib.h"
#include "../lib/stdio.h"
#include "../mmu/gdt.h"

void _irqClavier()
{
    uchar i = 0;
    do{
        i = in(0x64);
    }while((i&0x01) == 0);
    
    i = in(0x60);
//     On affiche le code de la touche appuyée, en convertissant le code numérique en chaîne de caractères.
    if(i<0x80){
        char letter_id[5];
        intToStr(i, letter_id);
        write(letter_id);
        write(" ");
    }
}

void _irqHorloge()
{
    static int nb_count = 0;
    nb_count++;
    nb_count = nb_count%100;
    if(!nb_count)
        write("Clock\n");
}

void _irqDefault()
{
    write("Default interruption\n");
}

void _sysCalls(int num_appel)
{
	u16 ds_select;
	u32 ds_base;
	struct GdtT_ *ds;
	uchar *message;
	int lettre;

	if (num_appel == 1){
		asm("mov 44(%%ebp), %%eax \n \
        	mov %%eax, %0" : "=m"(lettre));
		putchar(lettre);
		putchar('\n');
	}
	else if (num_appel==2) {
		asm("mov 44(%%ebp), %%eax \n \
        	mov %%eax, %0  \n \
        	mov 24(%%ebp), %%ax \n \
        	mov %%ax, %1" : "=m"(message), "=m"(ds_select) : );
		ds = (struct GdtT_ *) (GDTADDR + (ds_select & 0xF8));
		ds_base = ds->base_0_15 + (ds->base_16_23 <<16) + (ds->base_24_31 << 24);
		write((char*) (ds_base + message));
	}
	else {
		write("syscall\n");
	}
	return;
}
