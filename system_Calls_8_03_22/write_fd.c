#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd1, fd2, fd3;

	char buff[200] = "Writing data to write.txt file\n";

//	fd1 = creat("open_fd1.txt", 0666);

	fd2 = open("write.txt", O_CREAT | O_RDWR, 0666);
		
	write(fd2 , buff, 50);

//	fd3 = creat("open_fd3.txt", 0666);

//	printf("File descriptor returned by fd1 is: %d\n",fd1);
	printf("File descriptor returned by fd2 is: %d\n",fd2);
//	printf("File descriptor returned by fd3 is: %d\n",fd3);

	close(fd2);

	return 0;
}
