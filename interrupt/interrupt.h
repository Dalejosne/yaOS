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
	#define out(port, value) asm("out dx, al; jmp 1f; 1:" :: "d" (port), "a" (value)) //un bit a en sortie sur port
	#define in(port) ({    \
        unsigned char _v;       \
        asm volatile ("in al, dx" : "=a" (_v) : "d" (port)); \
        _v;     \
    })
	#define cli asm("cli"::)//Active les interruptions
	#define sti asm("sti"::)//Les désactive
	
    //Définition des 
    #define EOI 0x20
    #define INT_TYPE 0x8E00




	//Structure des interruptions, et définition
	typedef struct IDT IDT;
    typedef struct IDTR IDTR;
	
	struct IDT
	{
		u16 offset0_15;
		u16 selector;
		u16 type;
		u16 offset16_31;
	}__attribute__ ((packed));
    
    struct IDTR
    {
        u16 limite;
        u32 base;
    }__attribute__((packed));

    #define IDT_LIM 0xFF //taille de la GDT
    #define IDT_BASE 0x800 //adresse physique de la GDT

    void init_idt_desc(u32 offset, u16 selector, u16 type, IDT* idt);
    void configure_pic();
    void init_idt();



	//Interrupt part for apic
#endif
