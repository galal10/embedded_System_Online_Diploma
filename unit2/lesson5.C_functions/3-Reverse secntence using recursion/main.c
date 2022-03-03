/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: galal
 */

#include "stdio.h"

void reverse();

int main(void)
{
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	reverse();
	return 0;
}

void reverse()
{
	char s;
	scanf("%c",&s);
	if(s !='\n')
	{
		reverse();
		printf("%c",s);
	}
}
