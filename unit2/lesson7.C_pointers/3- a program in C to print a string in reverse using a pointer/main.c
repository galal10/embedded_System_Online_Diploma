/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: galal
 */


#include <stdio.h>


int main(void)
{
	char str[50];
	char rev[50];

	char *ptr1=str;
	char *ptr2=rev;

	int i=-1;

	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	while(*ptr1)
	{
		*ptr1++;
		i++;
	}

	while(i>=0)
	{
		*ptr1--;
		*ptr2++=*ptr1;
		i--;
	}
	*ptr2 = '\0';
	printf("Reverse of the string : %s",rev);
	return 0;
}
