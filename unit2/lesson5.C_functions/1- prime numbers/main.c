/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: galal
 */

#include "stdio.h"

int check_prime(int n);

int main(void)
{
	int num1,num2;
	printf("Enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&num1,&num2);

	printf("Prime numbers between %d and %d are:",num1,num2);
	int i,flag;
	for(i=num1+1;i<=num2;++i)
	{
		flag=check_prime(i);
		if(flag ==0)
			printf("%d  ",i);
	}
	return 0;
}

int check_prime(int n)
{
	int i,flag=0;
	for(i=2;i<=n/2;++i)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	return flag;

}


