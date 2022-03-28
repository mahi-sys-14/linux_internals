#include<stdio.h>

int main()
{
	int num;

	do
	{
		printf("Enter the number:\n");
		scanf("%d", &num);
	}while(num < 0);

	int fact=1;

	for(int i=1; i <=num ; i++)
	{
		fact = fact*i;
	}

	printf("%d! = %d\n",num, fact);

	return 0;
}
