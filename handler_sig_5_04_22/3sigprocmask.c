#include<stdio.h>
#include<signal.h>
#include<unistd.h>	//getpid()
#include<stdlib.h>

void printSignalSet(sigset_t *set)
{
	/* this listing of signals may be incomplete */
	const int sigList[] = {SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV};
	const char *sigNames[] = {"SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGABRT", "SIGFPE", "SIGKILL", "SIGSEGV"};

	const int sigLen = 8;

	for(int i=0; i<sigLen; i++)
	{
		int ret = sigismember(set, sigList[i]);
		if(ret == -1)
		{
			perror("sigismember");
			exit(EXIT_FAILURE);
		}
		else if(ret == 1)
		{
			printf("signal %s=%d is in the set.\n", sigNames[i], sigList[i]);
		}
		else
		{
			printf("signal %s=%d is not in the set.\n", sigNames[i], sigList[i]);
		}
	}
}

int main(void)
{
	sigset_t set;

	if(sigprocmask(0, NULL, &set) != 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	printf(".....Initial signal mask for this process\n");
	printSignalSet(&set);

	if(sigaddset(&set, SIGINT) != 0)
	{
		perror("sigaddset");
		exit(EXIT_FAILURE);
	}

	/* Tell OS that we want to mask our new set of signals---which now includes SIGINT */
	if(sigprocmask(SIG_SETMASK, &set, NULL) != 0)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

	/* now, SIGINT will be blocked */
	printf(".....New signal mask for this process\n");
	printSignalSet(&set);

	int secToSleep = 2;
	printf("Try ctrl+c. Try killing this process with kill - kill %d. Going to sleep for %d sec\n",getpid(), secToSleep);
	sleep(secToSleep);

	printf("sleep returned.\n");

	printf("Removing all signals from mask\n");
//	sigemptyset(&set);
	sigfillset(&set);

	sigprocmask(SIG_SETMASK, &set, NULL);
	printSignalSet(&set);

	sleep(1);
	printf("Exited normally\n");

	return 0;
}
