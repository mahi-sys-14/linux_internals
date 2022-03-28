#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>
#include<fcntl.h>

void *thread_func(void *);
pthread_t tid1, tid2;
int fd;

int main()
{
	fd = open("/etc/passwd", O_RDONLY);
	printf("File opened with fd: %d\n",fd);

	pthread_create(&tid1, NULL, thread_func, "Thread one");	
	pthread_create(&tid2, NULL, thread_func, "Thread two");
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	return 0;
}

void *thread_func(void *arg)
{
	char *str, buff[100];

	str = (char *) arg;

	int n, pid;

	pid = getpid();

	printf("\n%s: \t started with pid %d\n", str, pid);

	do
	{
		n = read(fd, buff, 100);
		printf("\n%s: process started pid %d\n",str, pid);
		printf("...................................\n");
		write(1,buff,n);
		printf("\n......................................\n");

		sleep(3);
	}while(n);

	printf("Finished for %s : pid : %d\n",str, pid);

	return NULL;
}
