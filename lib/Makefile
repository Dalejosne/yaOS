CC=gcc -m32 -g -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp -nostdlib

#lib statiques
io_o: lib_o
	$(CC) -c stdio.c
	
lib_o:
	$(CC) -c stdlib.c

#Libs partagées (par exp pour python)
stdio_so:
	$(CC) -shared stdio.c -c libstdio.so
clean:
	rm -rf *.o *.a *.so
