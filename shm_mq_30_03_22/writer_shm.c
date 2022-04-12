#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

int main()
{
	char *p;
	int id;

	id = shmget(48, 250, IPC_CREAT|0644); //KS
	if(id < 0)
	{
		perror("shmget");
		return 0;
	}

	printf("SHM ID: %d\n",id);
	p = shmat(id, 0, 0); // PAS--user space
	printf("Enter the data: \n");
	scanf("%s",p);


	return 0;
}
