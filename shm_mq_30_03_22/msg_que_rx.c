#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

struct msg_buf
{
	long mtype;
	char buff[512];
};

int main(int argc, char *argv[])
{
	struct msg_buf v;

	int id;
/*	if(argc != 2)
	{
		printf("usage..../mq_rx msg_type \n");
		printf("Example: mq_rx 5 \n");
		return 0;
	}*/

	id = msgget(55, IPC_CREAT|0644);	//msgget(key, perm);
/*	if(id < 0)
	{
		perror("msgget"); 	/// ./mq_rx 12 linux\0
		return 0;
	}*/

	printf("Id of message queue: %d\n",id);

	msgrcv(id, &v, sizeof(v), 1 ,0); // ./mq_rx 12
	printf("Data: %s\n",v.buff);
	//perror("msgrcv");

	return 0;
}
