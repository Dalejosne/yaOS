CC=gcc -m32 -Wall -g -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp -nostdlib

noyau_o:
	$(CC) -c *.c
clean:
	rm -rf *.o kernel
