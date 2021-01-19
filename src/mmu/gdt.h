#ifndef __GDT_H__
	#include "../lib/ktypes.h"
	#define __GDT_H__
	#define GDTSIZE 0xFF
	#define GDTADDR  0x0

	typedef struct GdtT_
	{
		u16 lim_0_15;
		u16 base_0_15;
		u8 base_16_23;
		u8 accessibility;
		u8 lim_16_19 : 4;
		u8 flags : 4;
		u8 base_24_31;
	}__attribute__((packed)) GdtT;
	
	typedef struct GdtPtr_
	{
		u16 size;
		u32 addr;
	}__attribute__((packed)) GdtPtr;
	
	void initGdt_(void);
	void initGdtDescriptor(u32 base, u32 limite, u8 accessibility, u8 other, GdtT *Gdt_Desc);
	#define initGdt() initGdt_(); asm("movw $0x18, %ax \n movw %ax, %ss \n movl $0x20000, %esp")

	#ifdef __GDT__
		GdtT Gdt[GDTSIZE];	/* GDT */
		GdtPtr Gdt_Ptr;		/* GDTR */
	#else
		extern GdtT Gdt[GDTSIZE];	/* GDT */
		extern GdtPtr Gdt_Ptr;
	#endif
#endif
