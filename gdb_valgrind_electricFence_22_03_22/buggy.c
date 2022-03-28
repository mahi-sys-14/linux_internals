#include<stdio.h>
#include<stdlib.h>

void buggy()
{
	int *intptr;
	int i;

	intptr = (int *)malloc(sizeof(int) * 5);

	printf("MALLOC checking:  addr=%08x and size=%d\n",intptr, sizeof(int)*5);

	for(int i=0; i<=9; i++)
	{
		*intptr = 10;
		printf("Value of ptr intptr = %d\n",(*intptr));
		intptr++;
//		--intptr;
		//printf("Value of ptr intptr = %d\n",(*intptr));
	}
}

int main()
{
	buggy();
	return 0;
}
