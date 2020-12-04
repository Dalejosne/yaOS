CC=gcc -m32 -g -Wall -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp -nostdlib

interrupt_o: int_asm exc_asm
	$(CC) -c *.c

<<<<<<< HEAD
irq_o: 
	nasm -f elf interrupt.asm -o irq.o
=======
int_asm: 
	nasm -f elf interrupt.asm -o int.o
exc_asm:
	nasm -f elf exception.asm -o exc.o
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e

clean:
	rm -rf *.o
