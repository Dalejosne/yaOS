#ifdef __i386__
	#include <lib/kio.h>
	#include <x86/task/task.h>
	#ifdef __x86_64__
		//TODO
	#else
		#include <x86/mmu/mmu.h>
		#include <x86/interrupt/interrupt.h>
	#endif
#endif
#ifdef __aarch64__
//TODO Ici daniel je te laisse gérer
#endif

extern char k_y;
extern char kattr;

int main(void);

void _start(void)
{
	k_y = 8;
	kattr = 0xA;
	write("\t\t\t\tOK\n");//Si le bootloader a fonctionné, on affiche OK en vert
	
	kattr = 0x7;
	write("Initialisating interruptions...\n");
	initInterruptions();
    
	kattr = 0x7;
	write("Initialisating the memory management unit...\n");
	initMmu();

	main();
}

int main()
{
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
