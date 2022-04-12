#include<stdio.h>
#include<stdlib.h>
#include<sys/sem.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<unistd.h>

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};

int get_release(void);
int get_semaforce(void);
struct sembuf sem_op;
union semun sem_union;
int sid;

int main()
{
	int i;
	sleep(3);

	sid = semget((key_t)10, 1, 0666|IPC_CREAT);
	printf("Semaforce id: %d\n",sid);

	sem_union.val = 2;

	if(semctl(sid, 0, SETVAL, sem_union) < 0)
		printf("error semctl");

	for(i=0; i<=5; i++)
	{
		get_semaforce();

		printf("\n%d: got the semaforce\n",getpid());
		sleep(1);
		printf("\n%d: released the semaforce\n",getpid());
		get_release();

		sleep(1);
	}

	if(semctl(sid, 0, IPC_RMID, sem_union) < 0)
		printf("Fails to delete the semaforce\n");
	else
		printf("Semaforce deleted\n");

	return 0;
}

int get_semaforce()
{
	sem_op.sem_num = 0;
	sem_op.sem_op = -1;
	sem_op.sem_flg = SEM_UNDO;

	if(semop(sid, &sem_op, 1) < 0)
	{
		printf("Failed\n");
		return -1;
	}
}

int get_release()
{
	sem_op.sem_num = 0;
	sem_op.sem_op = 1;
	sem_op.sem_flg = SEM_UNDO;

	if(semop(sid, &sem_op, 1) < 0)
	{
		printf("Failed\n");
		return -1; //exit(-1);
	}
}

