#define TASK
#include "../lib/stdlib.h"
#include "../kernel/gdt.h"
#include "../lib/types.h"
#include "task.h"

void task1(void)
{
    while(1);
    return;
}

//Cette fonction initialise la gdt et copie la tâche en mémoire
void initTask(){

	default_task_i.memory_emplacement = 0x300000;//Uniquement nécéssaire que le code ne corrompe pas la pile
	default_task_i.size = 100;//La tâche est toute petite, on lui attribue juste 100 o.
	memcpy(&task1, (char*) default_task_i.memory_emplacement, default_task_i.size);

	//     Initialisation des descripteurs de segment utilisateur
    init_gdt_descriptor(default_task_i.memory_emplacement, 0x0, 0xFF, 0x0D, gdt+4); /* ucode */
    init_gdt_descriptor(default_task_i.memory_emplacement, 0x0, 0xF3, 0x0D, gdt+5); /* udata */
    init_gdt_descriptor(0x0, 0x20,    0xF7, 0x0D, gdt+6); /* ustack */

    default_tss.debug_flag = 0x00;
    default_tss.io_map = 0x00;
    default_tss.esp0 = 0x20000;
    default_tss.ss0 = 0x18;
    // On la charge en gdt
    init_gdt_descriptor((u32) &default_tss, 0x67, 0xE9, 0x00, gdt+7);

	asm("  movw %%ss, %0 \n \
       movl %%esp, %1" : "=m" (default_tss.ss0), "=m" (default_tss.esp0) : );
}

void callTask()
{
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
