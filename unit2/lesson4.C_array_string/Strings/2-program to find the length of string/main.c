/*
 * main.c
 *
 *  Created on: Feb 14, 2022
 *      Author: galal
 */

#include "stdio.h"

int main(void)
{
	char c[100];

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(c);

	int i;

	for(i=0; c[i]!='\0'; i++);
	printf("Length of string: %d",i);

	return 0;
}
