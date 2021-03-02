#include <x86/interrupt/interrupt.h>
#include <lib/kio.h>
extern char k_y;
extern char kattr;

void initInterruptions(void){
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
}
