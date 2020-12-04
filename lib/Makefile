<<<<<<< HEAD
<<<<<<< HEAD
CC=gcc -m32 -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
=======
CC=gcc -m32 -g -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
>>>>>>> master
=======
CC=gcc -m32 -g -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp -nostdlib
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e

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
