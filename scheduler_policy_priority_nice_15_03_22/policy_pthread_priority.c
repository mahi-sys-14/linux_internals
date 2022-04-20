#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *my(void *i)
{
	printf("I am in %d thread\n",(int *)i);
}

int main()
{
	pthread_t tid;
	struct sched_param param;
	int policy, ret;

	/* scheduling parameters of target thread */
	ret=pthread_getschedparam(pthread_self(), &policy, &param);
	printf("In main thread ........................policy: %d..........priority: %d\n",policy, param.sched_priority);

	policy=SCHED_FIFO;

	param.sched_priority=3;

	pthread_setschedparam(pthread_self(), policy, &param);
	
	pthread_getschedparam(pthread_self(), &policy, &param);
	printf("In main thread ........................policy: %d..........priority: %d\n",policy, param.sched_priority);

	return 0;
}


