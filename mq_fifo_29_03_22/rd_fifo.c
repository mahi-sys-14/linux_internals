#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd;

	mkfifo("rd_wr_fifo", 0644);

	char arr1[100], arr2[100];
	while(1)
	{
		// open fifo for write only
		fd = open("rd_wr_fifo", O_WRONLY);

		//take an input arr2 string from user
		// 100 is maximum length
		fgets(arr2, 100, stdin);

		// write the input arr2 string on fifo
		//and close it
		write(fd, arr2, strlen(arr2));
		close(fd);

		// open fifo for read only
		fd = open("rd_wr_fifo", O_RDONLY);

		// read from fifo
		read(fd, arr1, 100);
		printf("user input: %s\n", arr1);
		
		close(fd);
	}

	return 0;
}
