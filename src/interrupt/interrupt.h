#ifndef __INTERRUPT__
	#define __INTERRUPT__
	
	#include "../lib/ktypes.h"
	/**
	 * :param port: port number to be write
	 * :param value: value to be write on port. sizeof(value) = 1o
	 */ 
	#define outb(port, value) asm("outb %%al, %%dx; jmp 1f; 1:": :"d" (port), "a" (value))/**
	 /**
	 * :param port: port number to be read
	 * :return: 1 o, read on port
	 * 
	 * 
	 */ 
	#define in(port) ({    \
        unsigned char _v;       \
        asm volatile ("inb %%dx, %%al" : "=a" (_v) : "d" (port)); \
        _v;     \
    })
	
	/**
	 * Enable interrupt
	 */
	#define cli asm("cli"::)//Active les interruptions
	
	/**
	 * Disable interrupt
	 * 
	 * 
	 */
	#define sti asm("sti"::)//Les désactive
	
    /**
	  * End of interrupt signal
	  */
    #define EOI 0x20
    /**
	  * base type for interrupt 
	  */
    #define INT_TYPE 0x8E00
    
    /**
	  * base type for syscall (when initialisating one of the idt descriptor) 
	  * 
	  * 
	  */
    #define SYSCALL_TYPE 0xEF00



	/**
	 * Interrupt descriptor table structure in memory
	 */
	typedef struct Idt_
	{
		u16 offset0_15;
		u16 selector;
		u16 type;
		u16 offset16_31;
	}__attribute__ ((packed)) Idt;
    
	/**
	 * Interrupt descriptor table pointer descriptor
	 * 
	 * 
	 */
    typedef struct IdtR_
    {
        u16 limite;
        u32 base;
    }__attribute__((packed)) IdtR;

	 
	 /**
	  * IDT size
	  */
    #define IDT_LIM 0xFF
    
    /**
	  * IDT adress
	  * 
	  * 
	  */
    #define IDT_BASE 0x800 //adresse physique de la GDT

    
    /**
	 * Initialisate one of the descriptor located in the idt :
	 * 
	 * :param offset: Adress of the function to be call when an interrupt is emit
	 * :param selector: see intel doc
	 * :param type: See intel doc
	 * :param idt: Pointer of the idt to be initialisate
	 * 
	 * 
	 */
    void initIdtDescriptor(u32 offset, u16 selector, u16 type, Idt* idt);
    void configurePic();
    void initIdt();

	void _irqClavier();
	void _irqHorloge();
	/***/
	void _sysCalls(int num_appel);

	/**
	* Interrupt part for pic8259A
	*/
	/**
	* pic maître sur 0x20 et 0x21
	*/
	#define PIC_M_0 0x20
	#define PIC_M_1 0x21 
	/**
	* pic esclave sur 0xA0 et 0xA1
	* 
	* 
	*/
	#define PIC_E_0 0xA0 
	#define PIC_E_1 0xA1
	//Interrupt part for apic
#endif
