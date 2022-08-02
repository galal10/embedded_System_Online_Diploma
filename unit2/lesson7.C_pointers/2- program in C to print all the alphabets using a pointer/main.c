/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: galal
 */


#include <stdio.h>



int main(void)
{
	char alpha[27];
	char* ptr;
	int i;

	ptr = alpha;
	for(i=0;i<26;i++)
	{
		*ptr=i+'A';
		ptr++;
	}

	ptr=alpha;

	for(i=0;i<26;i++)
		printf(" %c ", *ptr++);

	printf("\n");
	return 0;
}
