/* linker script cortex-m3
Eng. Galal Nasser */

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rdata)
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

	. = ALIGN(4);
	. = . + 0x1000;
	_stack_top = .;
}