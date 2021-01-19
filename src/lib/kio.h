#ifndef __I386_TYPE__
	#include "ktypes.h"
#endif

#ifndef __STDIO__
	#define __STDIO__
	/**
	 * :param string: string to be write on the screen
	 * 
	 * 
	 */
	void write(char *string);
	
	/**
	 * :param n: number of char which the screen have to be scrolled
	 * 
	 * 
	 */
	void scrollup(unsigned int n);
	
	/**
	 * :param c: character to be write on the screen
	 * 
	 * 
	 */
	int putchar(int c);

#endif
