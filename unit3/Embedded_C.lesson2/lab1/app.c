#include "Uart.h"

unsigned char string_buffer[100] = "learn-in-depth: Galal";
unsigned const char string_buffer2[100] = "to create a rodata section";

void main(void)
{
	Uart_send_string(string_buffer);
}