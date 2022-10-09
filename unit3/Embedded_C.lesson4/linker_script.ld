/* linker script cortex-m4
Eng. Galal Nasser */

MEMORY
{
	flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		. = ALIGN(4);
		_E_text = .;
	}> flash

	.data : {
		. = ALIGN(4);
		_S_DATA = .;
		*(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}> sram AT>flash

	.bss : {
		. = ALIGN(4);
		_S_bss = .;
		*(.bss*)
		. = ALIGN(4);
		*(COMMON*)
		. = ALIGN(4);
		_E_bss = .;
	}> sram
}