#include<stdio.h>
#include<netdb.h>



int main()
{
	struct hostent *lh = gethostbyname("127.0.0.1");

	if(lh)
		puts(lh->h_name);
	else
		perror("gethostbyname");

	return 0;
}
