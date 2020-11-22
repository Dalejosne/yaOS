#include "interrupt.h"
#include "../lib/stdlib.h"
#include "../lib/stdio.h"
#include "../kernel/gdt.h"

void _irq0(void);
void _irq1(void);
void _irq2(void);
void _irqLogicielle(void);

static Idt idt[IDT_LIM];
static IdtR _Idt_R;

void initIdtDescriptor(u32 offset, u16 selector, u16 type, Idt* idt)
{
    idt->offset0_15 = offset & 0xFFFF;
    idt->offset16_31 = (offset & 0xFFFF0000) >> 16;
    idt->selector= selector;
    idt->type = type;
}

void configurePic()
{   out(0x20, 0x18);
    out(0xA0, 0x18);//On configure ICW1;
    
    out(0x21, 0x20);//Adresse de départ des vect d'int = 0x20
    out(0xA1, 0x70);

    out(0x21, 0x04);
    out(0xA1, 0x02);

    out(0x21, 0x0);
    out(0xA1, 0x0);
}

void initIdt()
{
    //Initialisation des descripteur d'interruption par défaut
    for(int i = 0; i<IDT_LIM;i++)
        initIdtDescriptor((u32) _irq2, 0x08, INT_TYPE, idt+i);
    
    //Initialisation des descripteur d'interruption du clavier et de l'horloge
    initIdtDescriptor((u32) _irq0, 0x08, INT_TYPE, idt+32); //horloge
    initIdtDescriptor((u32) _irq1, 0x08, INT_TYPE, idt+33); //clavier
    initIdtDescriptor((u32) _irqLogicielle, 0x08, 0xEF00, idt+48);
    
    //Initialisation de idtr
    _Idt_R.base = IDT_BASE;
    _Idt_R.limite = IDT_LIM*8;
    
    memcpy((char*) idt, (char*)_Idt_R.base, _Idt_R.limite);
    
    asm("lidt (_Idt_R)");
}
void _irqClavier()
{
    uchar i = 0;
    do{
        i = in(0x64);
    }while((i&0x01) == 0);
    
    i = in(0x60);
//     On affiche le code de la touche appuyée, en convertissant le code numérique en chaîne de caractères.
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

void _irqHorloge()
{
    static int nb_count = 0;
    nb_count++;
    nb_count = nb_count%100;
    if(!nb_count)
        write("Clock\n");
}

void _irqDefault()
{
    write("Default interruption\n");
}

void _sysCalls(int num_appel)
{
  u16 ds_select;
  u32 ds_base;
  struct GdtT_ *ds;
  uchar *message;

  if (num_appel==1) {
    asm("mov 44(%%ebp), %%eax \n \
         mov %%eax, %0  \n \
         mov 24(%%ebp), %%ax \n \
         mov %%ax, %1" : "=m"(message), "=m"(ds_select) : );
    ds = (struct GdtT_ *) (GDTADDR + (ds_select & 0xF8));
    ds_base = ds->base_0_15 + (ds->base_16_23 <<16) + (ds->base_24_31 << 24);
    write((char*) (ds_base + message));
    } else {
    write("syscall\n");
    }
    return;
    }

