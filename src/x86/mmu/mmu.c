#include "gdt.h"
#include "mmu.h"
#include "../../lib/kio.h"
extern char k_y;
extern char kattr;

void initMmu(void){
	kattr = 0x7;
	write("Loading new gdt...");
	
	initGdt();
	
	initPaging();
}

void initPaging(void){
	kattr = 0xA;
	write("\t\tOK\n");
}
