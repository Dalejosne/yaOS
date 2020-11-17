#include "interrupt.h"
#include "../lib/stdlib.h"
#include "../lib/stdio.h"

void _irq_0(void);
void _irq_1(void);
void _irq_2(void);

static IDT idt[IDT_LIM];
static IDTR idtr;

void init_idt_desc(u32 offset, u16 selector, u16 type, IDT* idt)
{
    idt->offset0_15 = offset & 0xFFFF;
    idt->offset16_31 = (offset & 0xFFFF0000) >> 16;
    idt->selector= selector;
    idt->type = type;
}

void configure_pic()
{
    out(0x20, 0x18);
    out(0xA0, 0x18);//On configure ICW1;
    
    out(0x21, 0x20);//Adresse de départ des vect d'int = 0x20
    out(0xA1, 0x70);

    out(0x21, 0x04);
    out(0xA1, 0x02);

    out(0x21, 0x0);
    out(0xA1, 0x0);
}

void init_idt()
{
    //Initialisation des descripteur d'interruption par défaut
    for(int i = 0; i<IDT_LIM;i++)
        init_idt_desc((u32) _irq_2, 0x08, INT_TYPE, idt+i);
    
    //Initialisation des descripteur d'interruption du clavier et de l'horloge
    init_idt_desc((u32) _irq_0, 0x08, INT_TYPE, idt+32); //horloge
    init_idt_desc((u32) _irq_1, 0x08, INT_TYPE, idt+33); //clavier
    
    //Initialisation de idtr
    idtr.base = IDT_BASE;
    idtr.limite = IDT_LIM*8;
    
    memcpy((char*) idt, (char*)idtr.base, idtr.limite);
    
    asm("lidt (idtr)");
}
void irq_clavier()
{
    uchar i = 0;
    do{
        i = in(0x64);
    }while((i&0x01) == 0);
    
    i = in(0x60);
//     On affiche le code de la touche appuyée 
    if(i<0x80){
        char letter[5] = "000 ";
        for(int ind = 0; ind<3; ind++)
        {
            int puiss = 1;
            for(int pow = 0; pow<2-ind; pow++)
                puiss*=10;
            uchar x = i/puiss;
            i%=(puiss);
            letter[ind] = x+48;
        }
        write(letter);
    }
}

void irq_horloge()
{
    static int nb_count = 0;
    nb_count++;
    nb_count = nb_count%100;
    if(!nb_count)
        write("Clock\n");
}

void default_irq()
{
    write("Default interruption\n");
}
