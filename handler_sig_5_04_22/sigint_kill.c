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

	sigemptyset(&s_set);	// clearing the structure: no elements/signals in it

	sigaddset(&s_set, 2);	// inserting 2 signal in blocked state
	perror("sig2");

	sigprocmask(SIG_BLOCK, &s_set, NULL);	// blocking 2 & 4 signal
	perror("sigmask");

	check_blocked_sigs();

//	sleep(20);
	while(1);

	return 0;
}
