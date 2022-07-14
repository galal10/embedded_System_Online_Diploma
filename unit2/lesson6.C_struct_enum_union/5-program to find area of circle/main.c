/*
 * main.c
 *
 *  Created on: Jun 29, 2022
 *      Author: galal
 */


#include <stdio.h>

#define PI 3.1415
#define area(r) (PI*(r)*(r))


int main(void)
{
	int rad;
	printf("Enter the radius:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&rad);
	printf("Area=%.2f",area(rad));
	return 0;
}
