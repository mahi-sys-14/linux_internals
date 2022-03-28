#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd1, fd2, fd3, fd4;

	fd1 = open("dup1.txt", O_RDWR|O_CREAT|O_TRUNC, 0666);
	fd2 = open("dup2.txt", O_RDWR|O_CREAT|O_TRUNC, 0766);

	printf("Fd1: %d\n",fd1);
	printf("Fd2: %d\n",fd2);

	fd3=dup(fd1);

	printf("using dup \nfd2: %d dup_Fd3: %d\n",fd2,fd3);

	fd4=dup2(fd2, 12);
	printf("using dup2 \nfd1: %d dup_Fd4: %d\n",fd1,fd4);

	int fd5;

	fd5=fcntl(fd1, F_DUPFD, 565);
	printf("using fcntl dup2 \nfd1: %d dup_Fd5: %d\n",fd1,fd5);


	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);

	return 0;
}
