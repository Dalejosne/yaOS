#include <x86/interrupt/interrupt.h>
#include <lib/klib.h>
#include <lib/kio.h>
#include <x86/mmu/gdt.h>

static Idt idt[IDT_LIM];
static IdtR _Idt_R;

void _irqDef(void);
void _irq32(void);
void _irq33(void);
void _syscall(void);
void _irq0(void);
void _irq1(void);
void _irq2(void);
void _irq3(void);
void _irq4(void);
void _irq6(void);
void _irq7(void);
void _irq10(void);
void _irq11(void);
void _irq12(void);
void _irq13(void);
void _irq14(void);
void _irq16(void);
void _irq17(void);
void _irq18(void);
void _irq19(void);
void _irq20(void);
void _irq30(void); 
void _irqExcDefault(void);

void configurePic()
{
	outb(0x20, 0x18);
    outb(0xA0, 0x18);//On configure ICW1;
    
    outb(0x21, 0x20);//Adresse de départ des vect d'int = 0x20
    outb(0xA1, 0x70);

    outb(0x21, 0x04);
    outb(0xA1, 0x02);

    outb(0x21, 0x0);
    outb(0xA1, 0x0);
}

void initIdtDescriptor(u32 offset, u16 selector, u16 type, Idt* idt)
{
    idt->offset0_15 = offset & 0xFFFF;
    idt->offset16_31 = (offset & 0xFFFF0000) >> 16;
    idt->selector= selector;
    idt->type = type;
}

void initIdt()
{
    //Initialisation des descripteurs d'exceptions par défaut
    for(int i = 0; i<31;i++)
		initIdtDescriptor((u32) _irqExcDefault, 0x08, INT_TYPE, idt+i);
	//Initialisation des descripteurs d'exceptions
	initIdtDescriptor((u32) _irq0, 0x08, INT_TYPE, &idt[0]);
	initIdtDescriptor((u32) _irq1, 0x08, INT_TYPE, &idt[1]);
	initIdtDescriptor((u32) _irq2, 0x08, INT_TYPE, &idt[2]);
	initIdtDescriptor((u32) _irq3, 0x08, INT_TYPE, &idt[3]);
	initIdtDescriptor((u32) _irq4, 0x08, INT_TYPE, &idt[4]);
	initIdtDescriptor((u32) _irq6, 0x08, INT_TYPE, &idt[6]);
	initIdtDescriptor((u32) _irq7, 0x08, INT_TYPE, &idt[7]);
	initIdtDescriptor((u32) _irq10, 0x08, INT_TYPE, &idt[10]);
	initIdtDescriptor((u32) _irq11, 0x08, INT_TYPE, &idt[11]);
	initIdtDescriptor((u32) _irq12, 0x08, INT_TYPE, &idt[12]);
	initIdtDescriptor((u32) _irq13, 0x08, INT_TYPE, &idt[13]);
	initIdtDescriptor((u32) _irq14, 0x08, INT_TYPE, &idt[14]);
	initIdtDescriptor((u32) _irq16, 0x08, INT_TYPE, &idt[16]);
	initIdtDescriptor((u32) _irq17, 0x08, INT_TYPE, &idt[17]);
	initIdtDescriptor((u32) _irq18, 0x08, INT_TYPE, &idt[18]);
	initIdtDescriptor((u32) _irq19, 0x08, INT_TYPE, &idt[19]);
	initIdtDescriptor((u32) _irq20, 0x08, INT_TYPE, &idt[20]);
	initIdtDescriptor((u32) _irq30, 0x08, INT_TYPE, &idt[30]);
	
	//Initialisation des descripteurs d'interruption par défaut
    for(int i = 31; i<IDT_LIM;i++)
        initIdtDescriptor((u32) _irqDef, 0x08, INT_TYPE, &idt[i]);
    //Initialisation des descripteurs d'interruption du clavier et de l'horloge, et logicielles
    initIdtDescriptor((u32) _irq32, 0x08, INT_TYPE, &idt[32]); //horloge
    initIdtDescriptor((u32) _irq33, 0x08, INT_TYPE, &idt[33]); //clavier
    initIdtDescriptor((u32) _syscall, 0x08, SYSCALL_TYPE, &idt[48]);//logicielles (int 0x30)
    
    //Initialisation de idtr
    _Idt_R.base = IDT_BASE;
    _Idt_R.limite = IDT_LIM*8;
    
    kmemcpy((char*) idt, (char*)_Idt_R.base, _Idt_R.limite);
    
    asm("lidt (_Idt_R)");
}
