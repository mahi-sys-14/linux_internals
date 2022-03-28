#include<stdio.h>
#include<stdlib.h>

void buggy()
{
	int *intptr;
//	int i;

	intptr = (int *)malloc(sizeof(int));  // int data type = 4bytes

	printf("MALLOC checking:  addr=%08x and size=%d\n",intptr, sizeof(int));

		*intptr = 10;
		printf("Value of ptr intptr = %d\n",(*intptr));

		free(intptr); // we freee here dynamic allocated ptr
		*intptr = 19; //trying to derefer here...
//		--intptr;
		//printf("Value of ptr intptr = %d\n",(*intptr));

}

int main()
{
	buggy();
	return 0;
}
