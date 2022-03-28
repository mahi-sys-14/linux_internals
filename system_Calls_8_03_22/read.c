#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;
	int len=0;

	char write_buff[200] = "Writing data to write1.txt file to both read and write operation\n";
	char read_buff[50];

	fd1 = open("write1.txt", O_CREAT | O_RDWR, 0666);	
	len=write(fd1 , write_buff, 100);
	printf("File descriptor returned by fd1 is: %d and data written length is: %d\n",fd1,len);
	close(fd1);

	fd2 = open("write1.txt", O_CREAT | O_RDWR, 0666);
	read(fd2, read_buff, len);
	printf("File descriptor returned by fd2 is: %d\n",fd2);
	printf("File contents are: %s\n",read_buff);

	close(fd2);

	return 0;
}
