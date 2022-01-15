PREFIX=$(CURDIR)/../..
CC=gcc -m32 -g -Wall -fno-pie -fno-stack-protector -I$(PREFIX)/include/

#lib statiques
all:
	$(CC) -c *.c

clean:
	rm -rf *.o *.a *.so
