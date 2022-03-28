#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

pthread_t tid, tid2;

int sharedVar = 5; //global shared variable

void* thread(void *arg)
{

	printf("Newly created thread is executing\n");

	while(1);

	return NULL;
}

int main(void)
{
	int t=0;
	int ret=pthread_create(&tid, NULL, thread, NULL);

	if(ret)
		printf("thread not created\n");
	else
		printf("Thread is created\n");
	
	sleep(6);

	t=pthread_cancel(tid);

	if(t == 0)
		printf("Thread canceled\n");

	printf("Exiting main thread\n");
	
	return 0;
}
