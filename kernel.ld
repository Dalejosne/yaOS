OUTPUT_FORMAT(binary)
ENTRY(_start)

SECTIONS
{
	. = 0x1000;

	.text : {
		_TEXT_START = .;
		*(.text*)
		_TEXT_END = .;
	}

	.rodata : {
		_RODATA_START = .;
		*(.rodata*)
		_RODATA_END = .;
	}

	.data : {
		_DATA_START = .;
		*(.data*)
		_DATA_END = .;
	}

	.bss : {
		_BSS_START = .;
		*(.bss*)
		_BSS_END = .;
	}

	/DISCARD/ : {
		*(.comment*)
	}
}
