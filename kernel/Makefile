<<<<<<< HEAD
CC=gcc -m32 -Wall  -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
=======
CC=gcc -m32 -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
>>>>>>> ef4e64332338adca8b22483f1d26475accf48b41
LIB=-L ../lib -lstdio -lstdlib

noyau_o: gdt_o
	$(CC) -c kernel.c

gdt_o:
	$(CC) -c gdt.c
clean:
	rm -rf *.o
