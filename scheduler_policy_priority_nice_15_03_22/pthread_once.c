#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *my_init()
{
	printf("I am in my init \n");
}

void *my_thread(void *i)
{
	printf("\nI am in my thread func: %d\n",(int *)i);

	pthread_once(&once, (void *)my_init);

//	sleep(10);
	printf("Exit from %d my thread function\n", (int *)i);
}

int main()
{
	pthread_t thread1, thread2, thread3;

	pthread_create(&thread1, NULL, my_thread, (void *)1);
//	sleep(2);

	pthread_create(&thread2, NULL, my_thread, (void *)2);
//	sleep(2);

	pthread_create(&thread3, NULL, my_thread, (void *)3);

	printf("Exit from main thread\n");
	pthread_exit(NULL);
}

