#include "Uart.h"


void Uart_send_string(unsigned char *P_tx_string)
{
	while(*P_tx_string != '\0')
	{
		UART0DR = (unsigned int)(*P_tx_string);
		P_tx_string++; /* next char */
	}
}