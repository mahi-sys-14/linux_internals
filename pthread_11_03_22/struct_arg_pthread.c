#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<pthread.h>

pthread_t tid;

struct char_print_params
{
	char c;
	int count;
};

void* thread_arg(void *arg)
{
	struct char_print_params *s = (struct char_print_params *) arg;

	printf("Newly created thread is executing\n");
	printf("Character is: %c and count is: %d\n",s->c, s->count);

	return NULL;
}

int main(void)
{
	struct char_print_params t1_arg; 
	struct char_print_params t2_arg;

	t1_arg.c = 'm';
	t1_arg.count = 100;
	int ret=pthread_create(&tid, NULL, thread_arg, &t1_arg);

	t2_arg.c = 'v';
	t2_arg.count = 200;
	int ret1=pthread_create(&tid, NULL, thread_arg, &t2_arg);

	pthread_join(tid, NULL);

	printf("Exiting main thread\n");
	
	return 0;
}
