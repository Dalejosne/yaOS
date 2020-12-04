#define __TASK__
#include "../lib/stdlib.h"
#include "../kernel/gdt.h"
#include "../lib/types.h"
#include "task.h"

#define sysWrite(chaine) asm("mov %0, %%ebx; mov $0x02, %%eax; int $0x30" :: "m"(chaine))
#define sysPutchar(lettre) asm ("mov %0, %%ebx; mov $0x01, %%eax; int $0x30":: "g"(lettre))
#define sysDefault() asm ("mov $0x03, %eax; int $0x30")

void task1(void)
{
<<<<<<< HEAD
<<<<<<< HEAD
  char *msg=(char*) 0x100;
  msg[0] = 't' ;
  msg[1] = 'a' ;
  msg[2] = 'c' ;
  msg[3] = 'h' ;
  msg[4] = 'e' ;
  msg[5] = '\n';
  msg[6] = 0 ;
  asm("mov %0, %%ebx; mov $0x01, %%eax; int $0x30" :: "m" (msg));
  while(1);
  return;
=======
=======
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e
	char *msg=(char*) 0x100;
	msg[0] = 't' ;
	msg[1] = 'a' ;
	msg[2] = 'c' ;
	msg[3] = 'h' ;
	msg[4] = 'e' ;
	msg[5] = '\n';
	msg[6] = 0 ;
	sysWrite(msg);
<<<<<<< HEAD
	while(1);
	return;
>>>>>>> master
=======
	sysWrite(msg);
	sysWrite(msg);
	sysWrite(msg);
	while(1);
	return;
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e
}

//Cette fonction initialise la gdt et copie la tâche en mémoire
void initTask(){

	Default_Task_I.memory_emplacement = 0x300000;//Uniquement nécéssaire que le code ne corrompe pas la pile
	Default_Task_I.size = 100;//La tâche est toute petite, on lui attribue juste 100 o.
<<<<<<< HEAD
<<<<<<< HEAD
	memcpy((void*) &task1, (char*) Default_Task_I.memory_emplacement, Default_Task_I.size);
=======
	kmemcpy((void*) &task1, (char*) Default_Task_I.memory_emplacement, Default_Task_I.size);
>>>>>>> master
=======
	kmemcpy((void*) &task1, (char*) Default_Task_I.memory_emplacement, Default_Task_I.size);
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e

	//     Initialisation des descripteurs de segment utilisateur
    initGdtDescriptor(Default_Task_I.memory_emplacement, 0x0, 0xFF, 0x0D, Gdt+4); /* ucode */
    initGdtDescriptor(Default_Task_I.memory_emplacement, 0x0, 0xF3, 0x0D, Gdt+5); /* udata */
    initGdtDescriptor(0x0, 0x20,    0xF7, 0x0D, Gdt+6); /* ustack */

	//On initialise le segment de tâche par défaut
    Default_Tss.debug_flag = 0x00;
    Default_Tss.io_map = 0x00;
    Default_Tss.esp0 = 0x20000;
    Default_Tss.ss0 = 0x18;
    // On la charge en gdt
    initGdtDescriptor((u32) &Default_Tss, 0x67, 0xE9, 0x00, Gdt+7);

	asm("  movw %%ss, %0 \n \
       movl %%esp, %1" : "=m" (Default_Tss.ss0), "=m" (Default_Tss.esp0) : );
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
            iret" : "=m" (Default_Tss.esp0) : );
}
