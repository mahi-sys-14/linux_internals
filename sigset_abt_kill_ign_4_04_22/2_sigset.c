#include<stdio.h>
#include<signal.h>

void check_blocked_sigs()
{
	int i, res;
	sigset_t s;
	sigprocmask(SIG_BLOCK, NULL, &s);	//first param is not considered

	for(i=1; i<5; i++)
	{
		res = sigismember(&s, i);
		if(res)
			printf("signal %d is blocked \n",i);
		else
			printf("signal %d is not blocked \n",i);

	}
}

int main()
{
	sigset_t s_set;

	// filled the whole set...with all the signals
//	sigfillset(&s_set);	

	sigemptyset(&s_set);	// clearing the structure: no elements/signals in it

	sigaddset(&s_set, 1);	// inserting 1  signal in blocked state
//	perror("sig2");
	perror("sig1");

	sigaddset(&s_set, 4);	// inserting 4 signal in blocked state
	perror("sig4");

	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);	// blocking 2 & 4 signal
	perror("sigmask");

	check_blocked_sigs();

	sigemptyset(&s_set);	// clearing the structure: no elements/signals in it

	sigaddset(&s_set, 2);	// inserting 2 signal in blocked state
	perror("sig2");

	sigprocmask(SIG_BLOCK, &s_set, NULL);	// blocking 2 & 4 signal
	perror("sigmask");

	check_blocked_sigs();

	
/*
	sigprocmask(SIG_UNBLOCK, &s_set, NULL);		// unblocking all the signals
	printf("now signals are unblocked\n");

	check_blocked_sigs();
*/
	return 0;
}
