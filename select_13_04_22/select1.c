#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;
	fd_set read_set, write_set, except_set;
	char buf[100];
	struct timeval timeout;
	int n;

	timeout.tv_sec = 90;

	fd1 = open("./serv", O_RDWR);
	fd2 = open("./clie", O_RDWR);
	fd3 = open("./write", O_RDWR);

	FD_ZERO(&read_set);
	FD_ZERO(&write_set);
//	FD_ZERO(&except_set);

	FD_SET(fd1, &read_set);
	FD_SET(fd2, &read_set);
//	FD_SET(fd1, &write_set);
	FD_SET(fd3, &write_set);

	n = select(FD_SETSIZE, &read_set, &write_set, NULL, &timeout);
	if(n < 0)
	{
		perror("select: ");
		exit(1);
	}

	printf("no of file descriptors: %d\n",n);

	return 0;
}
