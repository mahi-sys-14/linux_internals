#include<stdio.h>
#include<unistd.h>

int fds[2];

void parent_code()
{
	char *buff1 = "aaaaaaaaaaaaaa";
	char *buff2 = "bbbbbbbbbbbbb";

	close(fds[0]);
	write(fds[1], buff1, 20);
	write(fds[1], buff2, 20);

	printf("\nend of parents\n");
}

void child_code()
{
	char buff[40];

	int n, i;
	close(fds[1]);

	n = read(fds[0], buff, 40);
	printf("no of chars read = %d\n",n);

	for(i=0; buff[i]; i++)
	{
		if(buff[i] >= 'a' && buff[i] <= 'z')
			buff[i] = buff[i] - 32;
	}

	printf("%s\n", buff);

	printf("\nend of child\n");
}

int main()
{
	int res , i;
	pid_t p;

	res = pipe(fds);

	/* fds[0] for reading and fds[1] for writing */
/*	if(res == -1)
	{
		perror("pipe");
		exit(1);
	}
*/

	p = fork();
	if(p ==0)
		child_code();
	else
		parent_code();

	return 0;
}
