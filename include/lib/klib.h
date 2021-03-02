#ifndef __STDLIB__
	#define __STDLIB__
	
	/**
	 * :param depart: adress of the first octet to be copied
	 * :param destination: adress where the first octet will be copied
	 * :param size: number of octet to be copied
	 */
	void kmemcpy(char* depart, char* destination, int size);
	
	/**
	 * :param nb: number to convert into a string. Must be positiv
	 * :param chaine: string where will be store the converted number.
	 */
	void intToStr(int nb, char chaine[]);

#endif
