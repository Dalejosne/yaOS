PREFIX=$(CURDIR)/../..
CC=gcc -m32 -Wall -g -fno-pie -fno-stack-protector -I$(PREFIX)/include/

noyau_o:
	$(CC) -c *.c
clean:
	rm -rf *.o kernel
