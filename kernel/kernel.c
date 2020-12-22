#include "../lib/stdio.h"
#include "../task/task.h"
#include "../interrupt/interrupt.h"
#include "../mmu/gdt.h"
#include "../interrupt/interrupt.h"

extern char k_y;
extern char kattr;

int main(void);

void _start(void)
{
	k_y = 8;
	kattr = 0xA;
	write("\t\t\t\tOK\n");

    kattr = 0x7;
    write("Configuring pic...");
    configurePic();//Configuration du pic
    kattr = 0xA;
    write("\t\tOK\n");
    
    kattr = 0x7;
    write("Loading idt...");
    initIdt();//Initialisation de l'idt
    kattr = 0xA;
    write("\t\t\tOK\n");
    
	kattr = 0x7;
	write("Loading new gdt...");
	
	initGdt(); //Initialisation de la nouvelle gdt

	main();
}

int main()
{
	kattr = 0xA;
	write("\t\tOK\n");
	
	kattr = 0x7;
    write("Enabling interrupts...");
    sti;
    
    kattr = 0xA;
    write("\t\tOK\n");
    
    kattr = 0x7;
    callTask();
	while(1);
    
    return 0;
}
