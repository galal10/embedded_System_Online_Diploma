/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	char char_check;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&char_check);
	if((char_check >= 'a' && char_check <= 'z') || (char_check >= 'A' && char_check <= 'Z'))
		printf("%c is an alphabet", char_check);
	else
		printf("%c is not an alphabet",char_check);

	return 0;
}
