#ifndef GDT_H
	#include "../lib/types.h"
	#define GDT_H
	#define GDTSIZE 0xFF
	#define GDTADDR  0x0

	struct gdt_t
	{
		u16 lim_0_15;
		u16 base_0_15;
		u8 base_16_23;
		u8 accessibility;
		u8 lim_16_19 : 4;
		u8 flags : 4;
		u8 base_24_31;
	}__attribute__((packed));
	
	struct gdt_ptr
	{
		u16 size;
		u32 addr;
	}__attribute__((packed));
	
	void initGdt(void);
	void init_descriptor(u32 base, u32 limite, u8 accessibility, u8 other, struct gdt_t *gdtdesc);
	#define init_gdt() initGdt(); asm("mov ax, 0x18 \n mov ss, ax \n mov esp, 0x20000")

	#ifdef __GDT__
		struct gdt_t gdt[GDTSIZE];	/* GDT */
		struct gdt_ptr gdtPtr;		/* GDTR */
	#else
		extern struct gdt_t gdt[GDTSIZE];	/* GDT */
		extern struct gdt_ptr gdtPtr;
	#endif
#endif
