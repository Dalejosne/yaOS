PREFIX=$(CURDIR)/../../..
CC=gcc -m32 -g -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp -I$(PREFIX)/include/

interrupt_o: int_asm exc_asm
	$(CC) -c *.c

int_asm: 
	nasm -f elf interrupt.asm -o int.o
exc_asm:
	nasm -f elf exception.asm -o exc.o

clean:
	rm -rf *.o
