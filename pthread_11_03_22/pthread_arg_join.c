#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

pthread_t tid, tid2;

void* thread_arg(void *arg)
{
	char *s = (char *) arg;

	printf("Newly created thread is executing\n");
	printf("String is: %s\n",s);

	return NULL;
}

int main(void)
{
	int ret=pthread_create(&tid, NULL, thread_arg, "Hello World\n");

	if(ret)
		printf("thread not created\n");
	else
		printf("Thread is created\n");

	pthread_join(tid, NULL);

	printf("Exiting main thread\n");
	
	return 0;
}
