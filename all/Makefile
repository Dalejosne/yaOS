LINK= ld -Ttext 1000 --oformat binary -m elf_i386

all : floppy

noyau: noyau_o interrupt_o task_o lib
	 $(LINK) ../kernel/kernel.o ../kernel/gdt.o ../task/task.o ../interrupt/irq.o ../interrupt/interrupt.o ../lib/stdio.o ../lib/stdlib.o -o ../kernel/kernel
	
noyau_o:
	make -C ../kernel

task_o:
	make -C ../task

interrupt_o:
	make -C ../interrupt

lib:
	make -C ../lib

bootloader:
	make -C ../bootloader
	
floppy: bootloader noyau
	cat ../bootloader/bootloader ../kernel/kernel /dev/zero | dd of=testOs.flp bs=512 count=2880

clean:
	rm -rf *.o *.a kernel
