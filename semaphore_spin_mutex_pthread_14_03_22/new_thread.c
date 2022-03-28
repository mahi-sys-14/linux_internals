#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void *process(void *arg)
{

	pthread_detach(pthread_self());

	/* process a client request */
	printf("Sleeping 2 sec\n");

	sleep(2);
	printf("slept 2 sec\n");
}

int main()
{
	pthread_t tid;
	int errno = pthread_create(&tid, NULL, process, NULL);

	if(errno)
		perror("Thread creation\n");

	pthread_exit(NULL);

	printf("Exiting main thread\n");
	return 0;
}
