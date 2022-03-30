#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	printf("Server listening\n");

	int ret = mkfifo("cli_ser_fifo" ,0644);
	if(ret == -1)
	{
		perror("fifo already exist");
	}

	// open fifo for read
	int fd = open("cli_ser_fifo", O_RDONLY);
	if(fd == -1)
	{
		perror("Cannot open fifo for read\n");
		return 0;
	}

	printf("\nFIFO OPEN\n");

	// read string (upto 100 characters)
	char server_receiver[100];
	memset(server_receiver, 0, sizeof(server_receiver));

	int res, len;

	read(fd, server_receiver, 100);
	printf("Received string in server: %s\n", server_receiver);

	printf("EOF Reached\n");

	close(fd);
	printf("FIFO Closed\n");

	return 0;
}
