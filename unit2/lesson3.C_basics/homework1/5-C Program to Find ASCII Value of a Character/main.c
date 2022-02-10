/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	char Character;
	printf("Enter a Character : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&Character);
	printf("ASCII value of %c = %i",Character,Character);
	return 0;
}

