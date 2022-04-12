#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void sighand(int no)
{
	printf("Interrupt signal rec'd\n");
}

int main()
{
	sigset_t s_set;
	signal(2, sighand);

	sigemptyset(&s_set);	// clearing the structure: no elements in it
	sigaddset(&s_set, 2);
	perror("sig2");

	sigaddset(&s_set, 4);
	perror("sig4");

	sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
	perror("sigmask");

	printf("send me signal one and see the effect now\n");
	getchar();
	getchar();

	sigprocmask(SIG_UNBLOCK, &s_set, NULL);
	printf("now signals are unblocked\n");

	while(1);

	return 0;
}
