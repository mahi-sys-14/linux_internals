#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signum)
{
	printf("Inside handler function\n");
}

int main()
{
	pid_t pid;
	int i, sig_no;

	signal(SIGUSR1, sig_handler);	//register signal handler

	printf("Inside the main process\n");

	pid = getpid();		//process ID of itself

	kill(pid, SIGUSR1);	// send SIGUSR1 to itself
	printf("sig_rest: Exiting main\n");

	return 0;
}
