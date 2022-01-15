PREFIX=$(CURDIR)/../../..
CC=gcc -m32 -g -Wall -fno-pie -fno-stack-protector -I$(PREFIX)/include/

interrupt_o: int_asm exc_asm
	$(CC) -c *.c

int_asm: 
	as interrupt.S -o int.o --32
exc_asm:
	as exception.S -o exc.o --32

clean:
	rm -rf *.o
