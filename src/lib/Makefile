CC=gcc -m32 -g -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp -I$(PREFIX)/include/

#lib statiques
all:
	$(CC) -c *.c

clean:
	rm -rf *.o *.a *.so
