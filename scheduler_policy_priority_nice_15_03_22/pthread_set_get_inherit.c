#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *my_func(void *arg)
{
	sleep(3);
	return NULL;
}

int main()
{
	pthread_t thread1;
	pthread_attr_t attr;
	int err, info;


	pthread_attr_init(&attr);

	printf("getting the inherit state\n");
	pthread_attr_getinheritsched(&attr, &info);

	switch(info)
	{
		case PTHREAD_INHERIT_SCHED:
			printf("Sched from it's own thread\n");
			break;
		case PTHREAD_EXPLICIT_SCHED:
			printf("Explicit defining it's own scheduling policy and priority\n");
			break;
	}

	printf("Setting the sched\n");
	pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	pthread_attr_getinheritsched(&attr, &info);

	switch(info)
	{
		case PTHREAD_INHERIT_SCHED:
			printf("Sched from it's own thread\n");
			break;
		case PTHREAD_EXPLICIT_SCHED:
			printf("Explicit defining it's own scheduling policy and priority\n");
			break;
	}

	pthread_create(&thread1, &attr, my_func, NULL); 
	return 0;
}
