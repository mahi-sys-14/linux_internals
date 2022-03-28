#include<stdio.h>
#include<unistd.h>

int main()
{
	int fds[2];
	int res , i;

	char *buff1 = "hello this is mahima vaghela";
	char *buff2 = "learning IPC pipe mechanism";

	char buffer[40];

	res = pipe(fds);

	/* fds[0] for reading and fds[1] for writing */
	if(res == -1)
	{
		perror("pipe");
		exit(1);
	}

	write(fds[1], buff1, 20);
	write(fds[1], buff2, 20);
	read(fds[0], buffer, 40);

	for(i=0; i<40; i++)
		printf("%c", buffer[i]);

	printf("\n");

	return 0;
}
