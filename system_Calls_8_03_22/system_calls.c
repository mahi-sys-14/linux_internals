#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;
	int len=0;

	char write_buff[] = "This is mahima\n";
		//"This is mahima Writing data to write1.txt file to both read and write operation\n";
//	char read_buff[100];

	fd1 = open("write1.txt", O_CREAT | O_RDWR, 0666);	
	len=write(fd1 , write_buff, sizeof(write_buff));
	printf("File descriptor returned by fd1 is: %d and data written length is: %d\n",fd1,len);
//	close(fd1);

//	lseek(fd1, 0, SEEK_SET);
	int curr=0;
	curr = lseek(fd1, -len, SEEK_CUR);
	printf("Current position of file is: %d\n",curr);

	char read_buff[len];

//	fd2 = open("write1.txt", O_CREAT | O_RDWR, 0666);
	read(fd1, read_buff, len);
	printf("File descriptor returned by fd2 is: %d\n",fd1);
	printf("File contents are: %s",read_buff);

	close(fd2);

	return 0;
}
