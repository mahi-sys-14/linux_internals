#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1;
	int file_size = 4000;

	fd1 = open("file_4k.txt", O_CREAT|O_RDWR|O_TRUNC, 0666);

	lseek(fd1, file_size-1, SEEK_SET);

	write(fd1, "", 1);

	close(fd1);

	return 0;
}
