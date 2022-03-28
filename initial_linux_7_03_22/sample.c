#include<stdio.h>

int x=100, y;

void main()
{
	int c,d;
	static int a=10, b;

	for(int i=0; i<10; i++)
	{
		printf("Value of x: %d value of a: %d\n", x, a);
	}

}
