#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

struct my_thread
{
	int id;
	char msg[20];
};

void *my_thread(void *arg)
{
	struct my_thread *mt = (struct my_thread *)arg;

	pthread_t thread_ID;

	thread_ID = pthread_self();
	printf("\n Thread ID: %u\n",thread_ID);

	printf("%d Thread message: %s\n",mt->id, mt->msg);

	return (void *) strlen(mt->msg);

}

int main()
{
	pthread_t th1, th2, th3, th4, thread_id;
	void *res4, *res3, *res2;

	struct my_thread t4, t2, t3;

	t4.id = 4;
	strcpy(t4.msg, "fourth");
	
	t3.id = 3;
	strcpy(t3.msg, "third");

	t2.id = 2;
	strcpy(t2.msg, "second");
	
	thread_id = pthread_self();
	printf("\n MAIN THREAD ID: %u\n",thread_id);

	pthread_create(&th4, NULL, my_thread, &t4);
	pthread_create(&th3, NULL, my_thread, &t3);
	pthread_create(&th2, NULL, my_thread, &t2);

	pthread_join(th4, &res4);
	pthread_join(th3, &res3);
	pthread_join(th2, &res2);

	printf("Return string length of fourth: %ld\n",(long)res4);
	printf("Return string length of Third: %ld\n",(long)res3);
	printf("Return string length of second: %ld\n",(long)res2);

	printf("Exiting from main\n");

	pthread_exit(NULL);
}
