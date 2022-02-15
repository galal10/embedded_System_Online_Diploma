/*
 * main.c
 *
 *  Created on: Feb 14, 2022
 *      Author: galal
 */

#include "stdio.h"

int main(void)
{
	char c[100],ch;

	printf("Enter a string : ");
	fflush(stdin); fflush(stdout);
	gets(c);

	printf("Enter a character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&ch);

	int i, count=0;

	for(i=0; c[i] !='\0'; i++)
	{
		if(ch == c[i])
			count++;
	}
	printf("Frequency of %c = %d",ch,count);

	return 0;
}
