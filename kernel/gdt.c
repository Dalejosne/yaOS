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
	
	initTask();
    
	gdtPtr.size = GDTSIZE*8;
	gdtPtr.addr = GDTADDR;
	
	memcpy((char*)gdt, (char*) gdtPtr.addr, gdtPtr.size);

	asm("lgdt [gdtPtr]");
	
	//On charge le task register
	asm("movw ax, 0x38 \n \
		ltr %ax");
	
	//On charge les segments, sauf celui de pile, et on long jump pour changer de mode
	asm("   movw ax, 0x10 \n \
            movw ds, ax       \n \
            movw es, ax       \n \
            movw fs, ax       \n \
            movw gs, ax     \n  \
            jmp 0x08 : next\n \
            next: \n");
}
