#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{
	pid_t pid;

	pid=fork();

	if(pid == 0)
	{
		sleep(5);
		int pid2;
		printf("I am child process pid =%d\n",getpid());
		pid2=wait(0);
		printf("Here child process is: %d\n",getpid());
	}
	else
	{
		int pid1;
		printf("I am parent process pid: %d\n",getpid());
//		pid1 = wait(0);

//		printf("parent saying child %d exited/terminated normally\n",pid1);
//		printf("I am parent process here pid: %d\n",getpid());
	}

	return 0;
}

