CC=gcc -m32 -Wall -masm=intel -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
LIB=-L ../lib -lstdio -lstdlib

noyau_o: gdt_o
	$(CC) -c kernel.c

gdt_o:
	$(CC) -c gdt.c
clean:
	rm -rf *.o
