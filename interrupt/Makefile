CC=gcc -m32 -g -Wall -masm=intel -L/usr/lib32 -fno-pie -no-pie -fno-stack-protector -lssp

interrupt_o: irq_o
	$(CC) -c interrupt.c

irq_o: 
	nasm -f elf interrupt.asm -o irq.o
