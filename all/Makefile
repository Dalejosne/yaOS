<<<<<<< HEAD
LINK = ld -Ttext 1000 --oformat binary -m elf_i386
=======
LINK = ld -Ttext 0x1000 --oformat binary -m elf_i386
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e

all : floppy

#L'ordre est important !!! ../kernel/kernelo doit être linké en premier !
noyau: noyau_o interrupt_o task_o lib
<<<<<<< HEAD
	 $(LINK) ../kernel/kernel.o ../kernel/gdt.o ../task/task.o ../interrupt/irq.o ../interrupt/interrupt.o ../lib/stdio.o ../lib/stdlib.o -o ../kernel/kernel
=======
	 $(LINK) ../kernel/*.o ../lib/*.o ../interrupt/*.o ../task/*.o -o kernel
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e
	 
clean: clean_noyau clean_task clean_interrupt clean_lib clean_bootloader
	rm -rf *.o *.a kernel testOs.flp
clean_noyau:
	make -C ../kernel clean

clean_task:
	make -C ../task clean

clean_interrupt:
	make -C ../interrupt clean

clean_lib:
	make -C ../lib clean

clean_bootloader:
	make -C ../bootloader clean

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
<<<<<<< HEAD
	cat ../bootloader/bootloader ../kernel/kernel /dev/zero | dd of=testOs.flp bs=512 count=2880
=======
	cat ../bootloader/bootloader kernel /dev/zero | dd of=testOs.flp bs=512 count=2880
>>>>>>> 47789b9ebbb4ea00fd23fc20c918f75b575a407e
