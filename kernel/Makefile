<<<<<<< HEAD
<<<<<<< HEAD
CC=gcc -m32 -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
LIB=-L ../lib -lstdio -lstdlib
=======
CC=gcc -m32 -Wall -g -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp
>>>>>>> master
=======
CC=gcc -m32 -Wall -g -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp -nostdlib
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e

noyau_o:
	$(CC) -c *.c
clean:
	rm -rf *.o kernel
