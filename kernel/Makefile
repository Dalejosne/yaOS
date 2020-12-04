<<<<<<< HEAD
CC=gcc -m32 -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
LIB=-L ../lib -lstdio -lstdlib
=======
CC=gcc -m32 -Wall -g -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
>>>>>>> master

noyau_o: gdt_o
	$(CC) -c kernel.c

gdt_o:
	$(CC) -c gdt.c
clean:
	rm -rf *.o kernel
