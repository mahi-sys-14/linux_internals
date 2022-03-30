#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	printf("Client process writing\n");

	char clientmsg[] = "linux system kernel programming\n";

	//open fifo for write
	int fd = open("cli_ser_fifo", O_WRONLY);
	if(fd == -1)
	{
		perror("can't open fifo for writing\n");
		return EXIT_FAILURE;
	}

	write(fd, clientmsg, strlen(clientmsg));

	close(fd);

	return 0;
}
