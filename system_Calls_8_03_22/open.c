#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;


	fd2 = open("linux1.c" , O_CREAT | O_RDWR, 0777);

	printf("File descriptor returned by file is: %d\n",fd2);

	close(fd2);

	return 0;
}
