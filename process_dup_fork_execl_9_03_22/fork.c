#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Current process1\n");

	fork();

	printf("Linux process2\n");

	fork();

	printf("Linux process3\n");

	fork();

	printf("Linux process4\n");

	while(1);

	return 0;
}
