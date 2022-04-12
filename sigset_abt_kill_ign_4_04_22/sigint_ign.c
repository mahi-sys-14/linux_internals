#include<stdio.h>
#include<signal.h>
#include<unistd.h>


int main()
{
	int i;

	signal(SIGINT, SIG_IGN);
//	signal(SIGINT, SIG_DFL);

	for(i=0; ;i++)
	{
		printf("%d: Inside main function\n",i);
		sleep(1);
	}

	return 0;
}

