#ifndef __INTERRUPT__
	#define __INTERRUPT__
	
	#include "../lib/types.h"
	//Interrupt part for pic8259A
	//Définition des ports utilisés
		//pic maître
		#define PIC_M_0 0x20
		#define PIC_M_1 0x21 
		//pic esclave
		#define PIC_E_0 0xA0 
		#define PIC_E_1 0xA1

	
	//Définition des instructions assembleur x86
	#define outb(port, value) asm("outb %%al, %%dx; jmp 1f; 1:": :"d" (port), "a" (value)) //un bit a en sortie sur port
	#define in(port) ({    \
        unsigned char _v;       \
        asm volatile ("inb %%dx, %%al" : "=a" (_v) : "d" (port)); \
        _v;     \
    })
	#define cli asm("cli"::)//Active les interruptions
	#define sti asm("sti"::)//Les désactive
	
    //Définition des 
    #define EOI 0x20
    #define INT_TYPE 0x8E00
    #define SYSCALL_TYPE 0xEF00



	//Structure des interruptions, et définition
	
	typedef struct Idt_
	{
		u16 offset0_15;
		u16 selector;
		u16 type;
		u16 offset16_31;
	}__attribute__ ((packed)) Idt;
    
    typedef struct IdtR_
    {
        u16 limite;
        u32 base;
    }__attribute__((packed)) IdtR;

    #define IDT_LIM 0xFF //taille de la GDT
    #define IDT_BASE 0x800 //adresse physique de la GDT

    void initIdtDescriptor(u32 offset, u16 selector, u16 type, Idt* idt);
    void configurePic();
    void initIdt();



	//Interrupt part for apic
#endif
