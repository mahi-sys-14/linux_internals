#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int p[2];	// p[0] p[1] indexes or subscripts of array p

	pipe(p); 	//fd0.....p[0] rd end and fd1......p[1] wr end
	printf("Read end of pipe: %d\t Write end of pipe: %d\n",p[0], p[1]);	// 3, 4,.........0 1 2 OS

	if(fork())
	{
		//parent

		char s[20];
		printf("In parent Enter data...\n");
		scanf("%s", s);	//wait user enter "15+1"
		write(p[1], s, strlen(s) +1);
	}
	else
	{
		// child -- 0

		char buf[20];

		printf("In child....\n");
		read(p[0], buf, sizeof(buf));
		printf("child process printing data. of parent process...%s\n",buf);
	}


	return 0;
}
