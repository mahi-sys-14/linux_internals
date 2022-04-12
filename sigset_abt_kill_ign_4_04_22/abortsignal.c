#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void abort_handler(int);

int main()
{
	pid_t pid;
	int i, sig_no;

	if(signal(SIGABRT, abort_handler) == SIG_ERR)		//register signal handler
	{
		fprintf(stderr, "Couldn't set signal handler\n");
		exit(1);	
	}

	printf("Inside the main process\n");

	abort();
	printf("sig_rest: Exiting main\n");

	exit(0);
}

void abort_handler(int signum)
{
	if(signum == SIGABRT)
		printf("Signal received: %d\n",signum);
	
	fprintf(stderr,"Caught SIGABRT, exiting handler function\n");
	exit(1);
}

