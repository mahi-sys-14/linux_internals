#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

typedef struct msg_buf
{
	long mtype;
	char buff[512];
}msg;

int main(int argc, char *argv[])
{
	msg v1, v2;

	int id, i;

	id = msgget(32, IPC_CREAT|0644);	//msgget(key, perm);
/*	if(id < 0)
	{
		perror("msgget"); 	/// ./mq_rx 12 linux\0
		return 0;
	}*/

	printf("Id of message queue: %d\n",id);

	i = msgrcv(id, &v1, sizeof(v1), 1 ,0);
	printf("Return value of msgrcv v1: %d\n",i);
	printf("Data v1: %s\n",v1.buff);

	i = msgrcv(id, &v2, sizeof(v2), 2 ,0); 
	printf("Return value of msgrcv v1: %d\n",i);
	printf("Data v2: %s\n",v2.buff);


	//perror("msgrcv");

	return 0;
}
