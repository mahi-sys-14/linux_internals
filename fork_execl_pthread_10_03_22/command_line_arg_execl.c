#include<stdio.h>

int main(int argc, char *argv[])
{
	int i;
	printf("File Name: %s\n",argv[0]);
	printf("Number of arguments are: %d\n",argc);
	printf("Arguments passed\n");

	for(int i=0; i<argc; i++)
		printf("%s\n",argv[i]);


	return 0;
}

