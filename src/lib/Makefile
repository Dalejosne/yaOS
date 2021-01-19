CC=gcc -m32 -g -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp

#lib statiques
io_o: lib_o
	$(CC) -c kio.c
	
lib_o:
	$(CC) -c klib.c

clean:
	rm -rf *.o *.a *.so
