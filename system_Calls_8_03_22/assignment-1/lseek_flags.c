#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;
	int len=0;

	char write_buff[] = "This is mahima Writing data to write1.txt file to both read and write operation\n";

	fd1 = open("write1.txt", O_CREAT | O_RDWR, 0666);	
	len=write(fd1 , write_buff, sizeof(write_buff));
	printf("File descriptor returned by fd1 is: %d and data written length is: %d\n",fd1,len);

	lseek(fd1, 0, SEEK_SET);

	char read_buff[len];

	read(fd1, read_buff, len);
//	printf("File descriptor returned by fd1 is: %d\n",fd1);
	printf("File contents are: %s",read_buff);
	close(fd1);

	int length=0;
	char buffer[]="Here I am using the concept of lseek and it's flags: SEEK_SET, SEEK_CUR, SEEK_END";
	int curr=0;

	curr = lseek(fd1, 0, SEEK_CUR);
	printf("Current position of file is: %d\n",curr);

	fd2 = open("write1.txt", O_RDWR, 0666);
	lseek(fd2, 0, SEEK_END);

	length = write(fd2 , buffer, sizeof(buffer));
	printf("File descriptor returned by fd2 is: %d and data written length is: %d\n",fd1,length);

	lseek(fd2, len, SEEK_SET);
	char buffer1[length];

	read(fd2, buffer1, length);
//	printf("File descriptor returned by fd1 is: %d\n",fd1);
	printf("File contents are: %s",buffer1);

	close(fd2);

	return 0;
}
