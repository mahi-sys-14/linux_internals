#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid_1;

	printf("Current process pid: %d\n",getpid());

	pid_1 = fork();
	printf("Pid_1: %d\n",pid_1);
	
	if(pid_1)
	{
		//sleep(5);
		printf("Pid_1: %d\n",pid_1);
		printf("new child process pid = %d\n",getpid());
		printf("new child parent process pid = %d\n",getppid());

		execl("/usr/bin/vim", "vi", "mahi.txt",0);
		printf("new child 2 process pid = %d\n",getpid());
		printf("new child 2 parent process pid = %d\n",getppid());

	}
	else
	{
		//sleep(3);
		printf("Pid_1: %d\n",pid_1);
		printf("parent process pid = %d\n",getpid());
		printf("parent parent process pid = %d\n",getppid());
	}

	while(1);

	return 0;
}
