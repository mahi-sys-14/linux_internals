#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Using ls command program\n");

	execl("/bin/ls", "ls", "-lh", 0);

	printf("Executing ls\n");
	printf("Executing ls\n");
	printf("Executing ls\n");

	return 0;
}
