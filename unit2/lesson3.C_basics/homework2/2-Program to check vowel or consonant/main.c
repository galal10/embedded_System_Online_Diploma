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
	printf("Enter an alphabet: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&char_check);
	if(char_check == 'a' || char_check == 'e' || char_check == 'i' || char_check == 'o' || char_check == 'u')
		printf("%c is a vowel", char_check);
	else if (char_check == 'A' || char_check == 'E' || char_check == 'I' || char_check == 'O' || char_check == 'U')
		printf("%c is a vowel", char_check);
	else
		printf("%c is a consonant", char_check);
}

