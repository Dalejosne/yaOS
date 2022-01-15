bootloader:
	as bootloader.S -o bootloader.o
	#mold bootloader.o -o bootloader --oformat binary -Ttext 0x0 -e 0x0
	ld -T boot.ld  bootloader.o -o bootloader.elf
	#output binary format is buggy, using objcopy in post processing instead
	objcopy -O binary bootloader.elf bootloader
clean:
	rm -rf bootloader *.o *.elf
