#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000
#define MSG_LEN 256
#define RESP_MSG_START 256

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

union semun sem_union;

int main()
{
	int semId, shmId;
	char *pshm;

	struct sembuf sem_op;

	semId = semget(MY_KEY, 1, 0666);
	if(semId < 0)
	{
		printf("Could not create a semaphore\n");
		return 0;
	}
	else
		printf("opened a semaphore id: %d\n",semId);

	/* create a shared memory segmnet */
	shmId = shmget(MY_KEY, SHM_SIZE, 0666);	
	if(shmId < 0)
	{
		printf("Could not create a shared memory\n");
		return (2);
	}

	pshm = shmat(shmId, NULL, 0);
	if(!pshm)
	{
		printf("Could not attach shared memory\n");
		return (3);
	}

	while(1)
	{
		printf("client: Enter some request message to send to server\n");
		fgets(pshm, MSG_LEN, stdin);

		/* send token from sempahore 1 : unlock */
		sem_op.sem_num = 0;
		sem_op.sem_op = 1;
		sem_op.sem_flg = 0;

		semop(semId, &sem_op, 1);
	
		/* wait for a token to semaphore 0 : lock */
		sem_op.sem_num = 0;
		sem_op.sem_op = -1;
		sem_op.sem_flg = 0;

		semop(semId, &sem_op, 1);

		puts(pshm+RESP_MSG_START);
	}

	return 0;
}

