#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;
	int len=0;

	char write_buff[] = "This is mahima\n";

	fd1 = open("fop1.txt", O_CREAT | O_RDWR, 0666);	
	len=write(fd1 , write_buff, sizeof(write_buff));
	printf("File descriptor returned by fd1 is: %d and data written length is: %d\n",fd1,len);

	lseek(fd1, 0, SEEK_SET);

	char read_buff[len];

	read(fd1, read_buff, len);
	printf("File descriptor returned by fd2 is: %d\n",fd1);
	printf("File contents are: %s",read_buff);

	fd2 = creat("fop2.txt", 0666);
	printf("File descriptor returned by fd2 is: %d\n",fd2);

	close(fd1);
	close(fd2);

	return 0;
}
