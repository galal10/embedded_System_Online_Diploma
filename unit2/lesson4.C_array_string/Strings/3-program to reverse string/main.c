/*
 * main.c
 *
 *  Created on: Feb 14, 2022
 *      Author: galal
 */

#include "stdio.h"
#include "string.h"

int main(void)
{
	char c[100], temp;

	printf("Enter the string : ");
	fflush(stdin); fflush(stdout);
	gets(c);

	int i = 0 , j = strlen(c)-1;
	while(i<j)
	{
		temp = c[i];
		c[i] = c[j];
		c[j] = temp;
		i++;
		j--;
	}
	printf("\nReverse string is :%s",c);
	return 0;
}
