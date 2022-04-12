#include<stdio.h>
#include<signal.h>

void sighand()
{
	printf("I have to wake up my boss now\n");
	alarm(5);
}

int main()
{
	signal(SIGALRM, sighand);
	alarm(5);

	while(1);

	return 0;
}

/* check manual fro info on settimer functions */
