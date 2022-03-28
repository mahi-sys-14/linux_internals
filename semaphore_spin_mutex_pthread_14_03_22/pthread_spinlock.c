#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockthread(void *t)
{
	int rc;
	int count=0;

	printf("Entered thread: %d, getting spinlock\n",(int *)t);

	rc = pthread_spin_lock(&spinlock);

	printf("%d: thread unlock the spinlock\n",(int *)t);
       	pthread_spin_unlock(&spinlock);

	printf("%d: thread complete\n",(int *)t);
 	return NULL;
}

int main()
{
	int rc;
	pthread_t tid;

	if(pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE) != 0)
		perror("init\n");
	
	printf("Main: Entering spin lock\n");
	pthread_spin_lock(&spinlock);

	printf("Main: Creating spinlockthread\n");
	pthread_create(&tid, NULL, spinlockthread, (int *)1);

	printf("Main: wait a bit holding the spin lock\n");
	sleep(5);

	printf("\nMain: unlocking main thread\n");
	rc=pthread_spin_unlock(&spinlock);

	if(rc == 0)
		printf("Thread unlocked successfully\n");
	else
		printf("Thread unlocked failes\n");

	printf("Main: wait for thread to end\n");
	pthread_join(tid, NULL);

	printf("Main completed\n");

	return 0;
}

