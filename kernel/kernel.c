#include "../lib/stdio.h"
#include "../task/task.h"
#include "../interrupt/interrupt.h"
#include "gdt.h"
#include "../interrupt/interrupt.h"

extern char kY;
extern char kattr;

int main(void);

void _start(void)
{
	kY = 8;
	kattr = 0xA;
	write("\t\t\t\tOK\n");

    kattr = 0x7;
    write("Configuring pic...");
    configure_pic();//Configuration du pic
    kattr = 0xA;
    write("\t\tOK\n");
    
    kattr = 0x7;
    write("Loading idt...");
    init_idt();//Initialisation de l'idt
    kattr = 0xA;
    write("\t\t\tOK\n");
    
	kattr = 0x7;
	write("Loading new gdt...");
    
	init_gdt(); //Initialisation de la nouvelle gdt

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
    
    callTask();
	while(1);
    
    return 0;
}
