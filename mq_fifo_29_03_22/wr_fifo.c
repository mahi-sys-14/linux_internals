#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd1;

	mkfifo("rd_wr_fifo", 0644);

	char str1[100], str2[100];
	while(1)
	{
		// open fifo for read only
		fd1 = open("rd_wr_fifo", O_RDONLY);

		// read from fifo
		read(fd1, str1, 100);
		printf("user input: %s\n", str1);
		
		close(fd1);
	
		// open fifo for write only
		fd1 = open("rd_wr_fifo", O_WRONLY);

		//take an input arr2 string from user
		// 100 is maximum length
		fgets(str2, 100, stdin);

		// write the input arr2 string on fifo
		//and close it
		write(fd1, str2, strlen(str2));
		close(fd1);
	}

	return 0;
}
