#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

pthread_t tid, tid2;

void* thread1(void *arg)
{
	//sleep(2);
	printf("Newly created thread is executing\n");
	for(int i=0; i<10000; i++)
		printf("thread1: %d\n",i);

	return NULL;
}

void* thread2(void *arg)
{
	//sleep(2);
	printf("Newly created thread2 is executing\n");
	for(int i=0; i<10000; i++)
		printf("thread2: %d\n",i);
	
	return NULL;
}

int main()
{
	int ret=pthread_create(&tid, NULL, thread1, NULL);
	int ret1=pthread_create(&tid2, NULL, thread2, NULL);

	if(ret && ret1)
		printf("thread not created\n");
	else
		printf("Thread is created\n");

//	sleep(3);

	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);

	printf("Exiting main thread\n");
	
	return 0;
}
