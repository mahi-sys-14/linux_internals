#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void toggleCase(char *buf, int cnt);

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

	semId = semget(MY_KEY, 1, 0666|IPC_CREAT);
	if(semId < 0)
	{
		printf("Could not create a semaphore\n");
		return 0;
	}
	else
		printf("opened a semaphore id: %d\n",semId);

	/* set initial token count of both semaphore to zeros */
	semctl(semId, 0, SETVAL, 0);
	//semctl(semId, 1, SETVAL, 0);

	/* create a shared memory segmnet */
	shmId = shmget(MY_KEY, SHM_SIZE, 0666|IPC_CREAT);	
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
		/* wait for a token from sempahore 0 */
		sem_op.sem_num = 0;
		sem_op.sem_op = -1;
		sem_op.sem_flg = 0;

		semop(semId, &sem_op, 1);

		/* process the message available in shared memory */
		printf("Got the semaphore\n");	
		strcpy(pshm+256, pshm);
		toggleCase(pshm+256, strlen(pshm+256));
		printf("processed the request message and placed response\n");
		
		/* send token to semaphore 1 */
		sem_op.sem_num = 0;
		sem_op.sem_op = 1;
		sem_op.sem_flg = 0;

		semop(semId, &sem_op, 1);
	}

	return 0;
}

void toggleCase(char *buf, int cnt)
{
	int i;

	for(i=0; i<cnt; i++)
	{
		if(buf[i] >= 'A' && buf[i] <= 'Z')
			buf[i] += 0x20;
		else if(buf[i] >= 'a' && buf[i] <= 'z')
			buf[i] -= 0x20;
	}
}
