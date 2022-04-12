#include<stdio.h>
#include<unistd.h>
#include<limits.h>

int main(int args,char *afrgv[])
{
	char hostname[HOST_NAME_MAX + 1 ];

	hostname[HOST_NAME_MAX] = 0;
	if(gethostname(hostname,HOST_NAME_MAX) == 0)
		puts(hostname);
	else
		perror("gethostname :");

	return 0;
}
