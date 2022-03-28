#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/mman.h>


void *proc(void *arg)
{
	sleep(3);
	printf("This is the created thread\n");

	return NULL;
}

int main()
{
	pthread_t tid;

	pthread_attr_t attr;

	void *stk;
	size_t SIZ;
	int err;

	size_t my_stksize = 300000;
	void *my_stack;

	pthread_attr_init(&attr);

	pthread_attr_getstacksize(&attr, &SIZ);
	pthread_attr_getstackaddr(&attr, &stk);

//	pthread_attr_getstack(&attr, &stk, &SIZ);

	printf("Default size: %ld Address: %08x\n",SIZ, stk);

	my_stack=(void *)malloc(my_stksize);
	
	printf("MALLOC size: %ld Address: %x\n",my_stksize, my_stack);

	pthread_attr_setstack(&attr, my_stack, my_stksize);

	pthread_create(&tid, &attr, proc, NULL);

	pthread_attr_getstack(&attr, &stk, &SIZ);

	printf("newly defined stack size: %ld Address: %x\n",SIZ, stk);

	sleep(5);

	return 0;
}
