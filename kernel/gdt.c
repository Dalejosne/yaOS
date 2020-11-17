#define __GDT__

#include "gdt.h"
#include "../lib/types.h"
#include "../lib/stdlib.h"
#include "../task/task.h"

void init_gdt_descriptor(u32 base, u32 limite, u8 accessibility, u8 other, gdt_t *gdtDesc)
{
	gdtDesc->lim_0_15 = (limite & 0xffff);
	gdtDesc->base_0_15 = (base & 0xffff);
	gdtDesc->base_16_23 = (base & 0xff0000) >> 16;
	gdtDesc->accessibility = accessibility;
	gdtDesc->lim_16_19 = (limite & 0xf0000) >> 16;
	gdtDesc->flags = (other & 0xf);
	gdtDesc->base_24_31 = (base & 0xff000000) >> 24;
	return;
}

void initGdt(void)
{
	//Initialisation des descripteurs de la variable globale gdt, représentant la gdt
	init_gdt_descriptor(0x0, 0x0, 0x0, 0x0, gdt+0);
	init_gdt_descriptor(0x0, 0xFFFFF, 0x9B, 0x0D, gdt+1);      /* code */
	init_gdt_descriptor(0x0, 0xFFFFF, 0x93, 0x0D, gdt+2);      /* data */
	init_gdt_descriptor(0x0, 0x0, 0x97, 0x0D, gdt+3); 		/*stack*/
	
	gdtPtr.size = GDTSIZE*8;
	gdtPtr.addr = GDTADDR;
	
	memcpy((char*)gdt, (char*) gdtPtr.addr, gdtPtr.size);

	asm("lgdt [gdtPtr]");
	asm("movw ax, 0x38 \n \
		ltr %ax");

	asm(".att_syntax noprefix");
	asm("movw %ss, 0x18\n \
		movl %esp, 0x20000");//ss = default_tss.ss0; esp = default_tss.esp0
    asm(".intel_syntax noprefix");
	//On charge les segments, sauf celui de pile
	asm("   movw ax, 0x10 \n \
            movw ds, ax       \n \
            movw es, ax       \n \
            movw fs, ax       \n \
            movw gs, ax     \n  \
            jmp 0x08 : next\n \
            next: \n");
	
}

void callTask(){
// On copie la tâche en mémoire. Elle est très petite, donc on la considère de taille = 100 octets
	memcpy(&task1, (char*) 0x30000, 100);

	//     Initialisation des descripteurs de segment utilisateur
    init_gdt_descriptor(0x30000, 0x0, 0xFF, 0x0D, gdt+4); /* ucode */
    init_gdt_descriptor(0x30000, 0x0, 0xF3, 0x0D, gdt+5); /* udata */
    init_gdt_descriptor(0x0, 0x20,    0xF7, 0x0D, gdt+6); /* ustack */
    
	//     On crée un tss par défaut pour notre tache
    TSS default_tss;

    default_tss.debug_flag = 0x00;
    default_tss.io_map = 0x00;
    default_tss.esp0 = 0x20000;
    default_tss.ss0 = 0x18;
    // On la charge en gdt
    init_gdt_descriptor((u32) &default_tss, 0x67, 0xE9, 0x00, gdt+7);
	asm(".att_syntax noprefix");
	asm("   cli \n \
            push $0x33 \n \
            push $0x30000 \n \
            pushfl \n \
            popl %%eax \n \
            orl $0x200, %%eax \n \
            and $0xffffbfff, %%eax \n \
            push %%eax \n \
            push $0x23 \n \
            push $0x0 \n \
            movl $0x20000, %0 \n \
            movw $0x2B, %%ax \n \
            movw %%ax, %%ds \n \
            iret" : "=m" (default_tss.esp0) : );
}
