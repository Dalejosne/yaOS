LINK = ld -T kernel.ld -m elf_i386
PREFIX = $(CURDIR)

all : floppy
floppy: bootloader kernel
	cat $(PREFIX)/src/x86/bootloader/bootloader build/kernel /dev/zero | dd of=testOs.flp bs=512 count=2880 iflag=fullblock

#L'ordre est important !!! ../kernel/kernel.o doit être linké en premier !
kernel: kernel_o interrupt_o task_o mmu_o lib
	$(LINK) $(PREFIX)/src/kernel/*.o $(PREFIX)/src/x86/mmu/*.o $(PREFIX)/src/lib/*.o $(PREFIX)/src/x86/interrupt/*.o $(PREFIX)/src/x86/task/*.o -o build/kernel
kernel_o:
	make -C $(PREFIX)/src/kernel
mmu_o:
	make -C $(PREFIX)/src/x86/mmu
task_o:
	make -C $(PREFIX)/src/x86/task
interrupt_o:
	make -C $(PREFIX)/src/x86/interrupt
lib:
	make -C $(PREFIX)/src/lib
bootloader:
	make -C $(PREFIX)/src/x86/bootloader
	 
clean: clean_kernel clean_task clean_interrupt clean_lib clean_bootloader clean_mmu clean_doc
	rm -rf *.o *.a build/kernel testOs.flp
clean_kernel:
	make -C $(PREFIX)/src/kernel clean
clean_task:
	make -C $(PREFIX)/src/x86/task clean
clean_interrupt:
	make -C $(PREFIX)/src/x86/interrupt clean
clean_lib:
	make -C $(PREFIX)/src/lib clean
clean_bootloader:
	make -C $(PREFIX)/src/x86/bootloader clean
clean_mmu:
	make -C $(PREFIX)/src/x86/mmu clean
clean_doc:
	make -C $(PREFIX)/doc clean

doc:
	make -C $(PREFIX)/doc html
