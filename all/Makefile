LINK = ld -Ttext 0x1000 --oformat binary -m elf_i386

all : floppy

#L'ordre est important !!! ../kernel/kernelo doit être linké en premier !
noyau: noyau_o interrupt_o task_o mmu_o lib
	 $(LINK) ../kernel/*.o ../mmu/*.o ../lib/*.o ../interrupt/*.o ../task/*.o -o kernel
	 
clean: clean_noyau clean_task clean_interrupt clean_lib clean_bootloader clean_mmu
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

clean_mmu:
	make -C ../mmu clean

noyau_o:
	make -C ../kernel

mmu_o:
	make -C ../mmu

task_o:
	make -C ../task

interrupt_o:
	make -C ../interrupt

lib:
	make -C ../lib

bootloader:
	make -C ../bootloader
	
floppy: bootloader noyau
	cat ../bootloader/bootloader kernel /dev/zero | dd of=testOs.flp bs=512 count=2880 iflag=fullblock
