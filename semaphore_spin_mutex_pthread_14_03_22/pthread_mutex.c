#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>
#include<semaphore.h>

pthread_t tid, tid2;
pthread_mutex_t myMutex;		//create mutex

int sharedVar = 5; //global shared variable

void* thread_inc(void *arg)
{
	pthread_mutex_lock(&myMutex); //take mutex
	sharedVar++;		// critical section
	pthread_mutex_unlock(&myMutex);	//release mutex
/*
	printf("Newly created thread is executing\n");
	printf("After incr + %d\n",sharedVar);
	printf("thread inc id: %ld\n",pthread_self());
*/
	return NULL;
}

void* thread_dec(void *arg)
{

	pthread_mutex_lock(&myMutex); //take mutex
	sharedVar--;		// critical section
	pthread_mutex_unlock(&myMutex);	//release mutex

/*	printf("Newly created thread2 is executing\n");
	printf("After dec - %d\n",sharedVar);
	printf("thread dec id: %ld\n",pthread_self());
*/
	return NULL;
}

int main()
{
	pthread_create(&tid, NULL, thread_inc, NULL);
	pthread_create(&tid2, NULL, thread_dec, NULL);

	pthread_mutex_init(&myMutex, NULL);		//initialize mutex

	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);

	printf("Shared variable: %d\n",sharedVar);
	printf("Exiting main thread\n");
	
	return 0;
}
