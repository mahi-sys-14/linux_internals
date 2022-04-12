#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>

#define KEY (1492)

int main()
{
	int semid;

	union semun
	{
		int val;
		struct semid_ds *buf;
		unsigned short *array;
	}arg;

	arg.val = 1;
	//arg.val = 2;
	
	semid = semget(KEY, 1, IPC_CREAT|0666);
	if(semid < 0)
	{
		fprintf(stderr, "unable to obtain semaphore.\n");
		exit(0);
	}

	if(semctl(semid, 0, SETVAL, arg) < 0)
	{
		fprintf(stderr, "Cannot set sempahore value.\n");
	}
	else
	{
		fprintf(stderr, "Semaphore %d Initialized\n",KEY);
	}

	return 0;
}
