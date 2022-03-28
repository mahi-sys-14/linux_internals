#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("my process pid : %d\n",getpid()); //getpid will give pid of current process
	printf("my parent process pid : %d\n",getppid()); //getppid will give parent pid of current process ......bash bourne shell

	printf("Linux kernel\n");

	while(1); // waiting.....infinite loop

	return 0;
}
