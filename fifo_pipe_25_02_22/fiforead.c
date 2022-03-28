#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	char s[20];
	int fd;

//	mkfifo("fifowrite1",0644);	//fifowrite1 is an pipe i.e. file named pipe created fifo(named fifo)

//	perror("mkfifo");

	printf("Before open()....\n");
	fd = open("fifowrite1",O_RDONLY);	//open fifo for write only
	printf("After open()....\n");

//	printf("Enter data....\n");
//	scanf("%s", s);
	//gets(s);

	read(fd, s, sizeof(s));
	printf("Data: %s\n",s);

//	write(fd, s, strlen(s) +1);	//std wt(); internally filewrite data to

	return 0;
}
