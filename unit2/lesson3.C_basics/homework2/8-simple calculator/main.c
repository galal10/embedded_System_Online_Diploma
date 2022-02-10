/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	char op;
	float num1 , num2;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdin);  fflush(stdout);
	scanf("%c",&op);

	printf("Enter two operands: ");
	fflush(stdin);  fflush(stdout);
	scanf("%f %f",&num1,&num2);

	switch(op)
	{
	case '+' :
		printf("%.2f + %.2f = %.2f", num1 , num2 , num1+num2);
		break;

	case '-' :
		printf("%.2f - %.2f = %.2f", num1 , num2, num1 - num2);
		break;

	case '*' :
		printf("%.2f * %.2f = %.2f", num1 , num2 , num1 * num2);
		break;

	case '/' :
		if(num2 != 0)
			printf("%.2f / %.2f = %.2f",num1 , num2 , num1 / num2);
		else
			printf("can't divide by zero");
		break;

	default :
		printf("error");
	}

	return 0;
}

