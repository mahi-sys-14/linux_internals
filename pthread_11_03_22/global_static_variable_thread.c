#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

pthread_t tid, tid2;

int sharedVar = 5; //global shared variable

void* thread_inc(void *arg)
{
	sharedVar++;

	printf("Newly created thread is executing\n");
	printf("After incr + %d\n",sharedVar);

	printf("thread inc id: %ld\n",pthread_self());

	return NULL;
}

void* thread_dec(void *arg)
{
//	int thread_inc_id;

	printf("Newly created thread2 is executing\n");
	sharedVar--;

	printf("After dec - %d\n",sharedVar);

	printf("thread dec id: %ld\n",pthread_self());

	return NULL;
}

int main(void)
{
	int ret=pthread_create(&tid, NULL, thread_inc, NULL);
	int ret1=pthread_create(&tid2, NULL, thread_dec, NULL);

	if(ret && ret1)
		printf("thread not created\n");
	else
		printf("Thread is created\n");

	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);

	printf("Exiting main thread\n");
	
	return 0;
}
