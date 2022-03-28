#include<stdio.h>
#include"myMain.h"

int main()
{
	int a, b, add=0, mul=0, sub=0;

	a=10;
	b=38;

//	getValues(a, b);	
	add = addition(a, b);
	mul = multiplication(a, b);
	sub = substraction(a, b);

	printf("Addition of %d & %d is %d\n",a,b,add);
	printf("Multiplication of %d & %d is %d\n",a,b,mul);
	printf("Substraction of %d & %d is %d\n",a,b,sub);

	return 0;
}
