#include "../lib/stdlib.h"

void task1(void)
{
    while(1);
    return;
}

// On copie la tâche en mémoire. Elle est très petite, donc on la considère de taille = 100 octets
memcpy(&task1, (char*) 0x30000, 100)
