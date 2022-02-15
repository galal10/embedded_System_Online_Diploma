/*
 * main.c
 *
 *  Created on: Feb 4, 2022
 *      Author: galal
 */


#include "stdio.h"

int main(void)
{
	float a[2][3];
	float b[2][2];
	int r,c;
	printf("Enter the elements of 1st matrix\n");
	for(r=0;r<2;r++)
	{
		for(c=0;c<2;c++)
		{
			printf("Enter a%d%d: ",r+1,c+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&a[r][c]);
		}
	}
	printf("Enter the elements of 2nd matrix\n");
		for(r=0;r<2;r++)
		{
			for(c=0;c<2;c++)
			{
				printf("Enter b%d%d: ",r+1,c+1);
				fflush(stdin); fflush(stdout);
				scanf("%f",&b[r][c]);
			}
		}
	printf("sum of matrix\n");
		for(r=0;r<2;r++)
		{
			for(c=0;c<2;c++)
			{
				printf("%.1f\t",a[r][c]+b[r][c]);
			}
			printf("\n");
		}
	return 0;
}
