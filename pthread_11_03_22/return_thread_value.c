#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#include<pthread.h>

pthread_t tid, tid2;

void* thread_arg(void *arg)
{
	char *s = (char *) arg;

	printf("Newly created thread is executing\n");
	printf("String is: %s\n",s);

	return (void *) strlen(s);
}

int main(void)
{
	void *res;

	int ret=pthread_create(&tid, NULL, thread_arg, "Hello World\n");

	if(ret)
		printf("thread not created\n");
	else
		printf("Thread is created\n");

	pthread_join(tid, &res);

	printf("Length of string is: %ld\n",(long)res);

	printf("Exiting main thread\n");
	
	return 0;
}
