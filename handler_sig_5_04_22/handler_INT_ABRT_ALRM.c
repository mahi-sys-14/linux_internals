#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

/* handler for SIGINT , SIGALRM and SIGABRT */
static void signal_handler(int signum)
{
	if(signum == SIGINT)
		printf("Caught SIGINT\n");
	else if(signum == SIGALRM)
		printf("Caught SIGALRM\n");
	else
	{
		printf("Caught SIGABRT\n");
		fprintf(stderr, "Unexpected signal\n");
		exit(EXIT_FAILURE);
	}

	/* this should never happen */
	exit(EXIT_SUCCESS);
}

int main()
{
	printf("In the main function\n");

	/* register signal handler as our signal handler for SIGINT */
	if(signal(SIGINT, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Can't handel SIGINT\n");
		exit(EXIT_FAILURE);
	}

	/* register signal handler as our signal handler for SIGALRM */
	if(signal(SIGALRM, signal_handler) == SIG_ERR)
	{
		fprintf(stderr, "Can't handel SIGALRM\n");
		exit(EXIT_FAILURE);
	}
	alarm(4);

	/* register signal handler as our signal handler for SIGABRT */
	if(signal(SIGABRT, SIG_DFL) == SIG_ERR)
	{
		fprintf(stderr, "Can't handel SIGABRT\n");
		exit(EXIT_FAILURE);
	}

//	sleep(2);
//	abort();

	/* register signal handler as our signal handler for SIGABRT */
	if(signal(SIGABRT, SIG_DFL) == SIG_ERR)
	{
		fprintf(stderr, "Can't handel SIGABRT\n");
		exit(EXIT_FAILURE);
	}

	for(;;)
		pause();

	return 0;
}
