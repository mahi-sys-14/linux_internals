#include<stdio.h>
#include<stdlib.h>

int main(int argc , char **argv)
{
	int i;
	printf("\n file name: %s\n",argv[0]);
	printf("total number of arguments: %d\n",argc);

	printf("\n arguments passed\n");

	for(i=0; i<argc; i++)
	{
		printf("%s\n",argv[i]);
	}

	return 0;
}
