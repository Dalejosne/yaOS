#include "types.h"
#include "stdio.h"

#define RAMSCREEN 0xB8000       /* debut de la memoire video */
#define SIZESCREEN 0xFA0        /* 4000, nombres d'octets d'une page texte */
#define SCREENLIM 0xB8FA0

char k_x = 0;                    /* position courante du curseur a l'ecran */
char k_y = 17;
char kattr = 0x0E;              /* attributs video des caracteres a afficher */


/*
 * 'scrollup' scrolle l'ecran (la console mappee en ram) vers le haut
 * de n lignes (de 0 a 25).
 */
void scrollup(u32 n)
{
<<<<<<< HEAD
        u8 *video, *tmp;

        for (video = (u8 *) RAMSCREEN;
             video < (u8 *) SCREENLIM; video += 2) {
                tmp = (u8 *) (video + n * 160);

                if (tmp < (u8 *) SCREENLIM) {
                        *video = *tmp;
                        *(video + 1) = *(tmp + 1);
                } else {
                        *video = 0;
                        *(video + 1) = 0x07;
                }
        }

        k_y -= n;
        if (k_y < 0)
                k_y = 0;
=======
	u8 *video, *tmp;

	for (video = (u8 *) RAMSCREEN;
		video < (u8 *) SCREENLIM; video += 2) {
		tmp = (u8 *) (video + n * 160);

		if (tmp < (u8 *) SCREENLIM) {
			*video = *tmp;
			*(video + 1) = *(tmp + 1);
		} else {
			*video = 0;
			*(video + 1) = 0x07;
		}
	}

	k_y -= n;
	if (k_y < 0) k_y = 0;
>>>>>>> master
}

int putchar(int c)
{
<<<<<<< HEAD
        u8 *video;

        if (c == 10) {          /* CR-NL */
                k_x = 0;
                k_y++;
        } else if (c == 9) {    /* TAB */
                k_x = k_x + 8 - (k_x % 8);
        } else if (c == 13) {   /* CR */
                k_x = 0;
        } else {                /* autres caracteres */
                video = (u8 *) (RAMSCREEN + 2 * k_x + 160 * k_y);
                *video = c;
                *(video + 1) = kattr;

                k_x++;
                if (k_x > 79) {
                        k_x = 0;
                        k_y++;
                }
        }

        if (k_y > 24)
                scrollup(0);
=======
	u8 *video;

	if (c == 10) {          /* CR-NL */
		k_x = 0;
		k_y++;
	} else if (c == 9) {    /* TAB */
		k_x = k_x + 8 - (k_x % 8);
	} else if (c == 13) {   /* CR */
		k_x = 0;
	} else {                /* autres caracteres */
		video = (u8 *) (RAMSCREEN + 2 * k_x + 160 * k_y);
		*video = c;
		*(video + 1) = kattr;

		k_x++;
		if (k_x > 79) {
			k_x = 0;
			k_y++;
		}
	}

	if (k_y > 24) scrollup(0);
>>>>>>> master
	return c;
}

/*
 * 'print' affiche a l'ecran, a la position courante du curseur, une chaine
 * de caracteres terminee par \0.
 */
void write(char *string)
{
	while (*string != 0) {
		putchar(*string);
		string++;
	}
}


