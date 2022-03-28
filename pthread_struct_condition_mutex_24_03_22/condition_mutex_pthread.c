#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// Declaration of thread condition variable
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;

// declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// pthread_mutex_init(&mutex, NULL);

int done = 1;

// thread function
void *foo(void *arg)
{
	char *str = (char *)arg;

	printf("Thread task called by: %s\n",str);
	// acquire a lock
	pthread_mutex_lock(&lock);
	if(done == 1)
	{
		// let's wait on condition variable cond1
		done = 2;

		printf("Waiting on condition variable cond1\n");
		pthread_cond_wait(&cond1, &lock);

		printf("After condition wait\n");
	}
	else
	{
		//done = 2;
		
		//let's signal condition variable cond1
	
		printf("Signaling Condition Variable cond1\n");
		pthread_cond_signal(&cond1);
	}

	//release lock
	pthread_mutex_unlock(&lock);

	printf("returning thread\n");

	return NULL;
}

int main()
{
	pthread_t tid1, tid2;

	// create thread 1
	pthread_create(&tid1, NULL, foo, "Thread one");

	// sleep for 1 sec so that thread 1
	// would get a chance to run first
	sleep(1);

	// let's wait on condition variable cond1
	
	done = 2;

	// create thread 2
	pthread_create(&tid2, NULL, foo, "Thread two");

	//wait for the completion of thread 2
	pthread_join(tid2, NULL);

	return 0;
}
