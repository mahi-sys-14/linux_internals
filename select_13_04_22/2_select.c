#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd1, fd2;
	fd_set read_set, write_set, except_set;
	char buf[100];
	struct timeval timeout;
	int n;

	timeout.tv_sec = 90;

	fd1 = open("./serv", O_RDWR);
	fd2 = open("./clie", O_RDWR);

	FD_ZERO(&read_set);
//	FD_ZERO(&write_set);
//	FD_ZERO(&except_set);

	FD_SET(fd1, &read_set);
	FD_SET(fd2, &read_set);

	n = select(FD_SETSIZE, &read_set, NULL, NULL, &timeout);
	if(n < 0)
	{
		perror("select: ");
		exit(1);
	}

	// test whether fd is ready or not
	if(FD_ISSET(fd1, &read_set))
	{
		printf("reading from fd1 (./serv) \n");
		n = read(fd1, buf, 10);
		printf("read %d from max\n", n);
	}

	//test whether fd2 is ready or not
	if(FD_ISSET(fd2, &read_set))
	{
		printf("reading from fd2 (./clie) \n");
		n = read(fd2, buf, 10);
		printf("read %d from max\n", n);
	}


	return 0;
}
