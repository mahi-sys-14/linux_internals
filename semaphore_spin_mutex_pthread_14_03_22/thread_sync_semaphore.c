#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>
#include<semaphore.h>

pthread_t tid, tid2;
sem_t mySem;		//create semaphore

int sharedVar = 5; //global shared variable

void* thread_inc(void *arg)
{
	sem_wait(&mySem); //take semaphore
	sharedVar++;		// critical section
	sem_post(&mySem);	//release sempahore
/*
	printf("Newly created thread is executing\n");
	printf("After incr + %d\n",sharedVar);
	printf("thread inc id: %ld\n",pthread_self());
*/
	return NULL;
}

void* thread_dec(void *arg)
{
//	sharedVar--;

	sem_wait(&mySem);
	sharedVar--;
	sem_post(&mySem);

/*	printf("Newly created thread2 is executing\n");
	printf("After dec - %d\n",sharedVar);
	printf("thread dec id: %ld\n",pthread_self());
*/
	return NULL;
}

int main(void)
{
	int ret=pthread_create(&tid, NULL, thread_inc, NULL);
	int ret1=pthread_create(&tid2, NULL, thread_dec, NULL);

	sem_init(&mySem, 0, 1);		//initialize semaphore

	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);

	printf("Shared variable: %d\n",sharedVar);
	printf("Exiting main thread\n");
	
	return 0;
}
