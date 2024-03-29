#define __GDT__

#include <x86/mmu/gdt.h>
#include <lib/ktypes.h>
#include <lib/klib.h>
#include <x86/task/task.h>

void initGdtDescriptor(u32 base, u32 limite, u8 accessibility, u8 flags, GdtT *Gdt_Desc)
{
	Gdt_Desc->lim_0_15 = (limite & 0xffff);
	Gdt_Desc->base_0_15 = (base & 0xffff);
	Gdt_Desc->base_16_23 = (base & 0xff0000) >> 16;
	Gdt_Desc->accessibility = accessibility;
	Gdt_Desc->lim_16_19 = (limite & 0xf0000) >> 16;
	Gdt_Desc->flags = (flags & 0xf);
	Gdt_Desc->base_24_31 = (base & 0xff000000) >> 24;
	return;
}

void initGdt_(void)
{
	//Initialisation des descripteurs de segment noyeau
	initGdtDescriptor(0x0, 0x0, 0x0, 0x0, Gdt+0);
	initGdtDescriptor(0x0, 0xFFFFF, 0x9B, 0x0D, Gdt+1);      /* code */
	initGdtDescriptor(0x0, 0xFFFFF, 0x93, 0x0D, Gdt+2);      /* data */
	initGdtDescriptor(0x0, 0x0, 0x97, 0x0D, Gdt+3); 		/*stack*/
	
	//Initialisation des descripteurs de segment utilisateur
	initTaskGdt();
    
	//Initialisation des descripteurs de segment utilisateur
	Gdt_Ptr.size = GDTSIZE*8;
	Gdt_Ptr.addr = GDTADDR;
	
	//Chargement de la gdt en mémoire
	
	kmemcpy((char*)Gdt, (char*) Gdt_Ptr.addr, Gdt_Ptr.size);

	asm("lgdt (Gdt_Ptr)\n");
	
	//Ici, on charge aussi le task register, comme l'on ne peut pas le faire avant de charger la gdt 
	asm("movw $0x38, %ax \n \
		ltr %ax\n");
	
	//On charge les segments, sauf celui de pile
	asm("   movw $0x10, %ax \n \
            movw %ax, %ds       \n \
            movw %ax, %es       \n \
            movw %ax, %fs       \n \
            movw %ax, %gs     \n  \
            jmp $0x08, $next\n \
            next: \n");
	
}
