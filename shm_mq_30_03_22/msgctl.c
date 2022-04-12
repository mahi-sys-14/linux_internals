#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

//#define KEY 8979

int main(int argc, char *argv[])
{
	int id, i;
	struct msqid_ds mybuff;

	id = msgget(32, IPC_CREAT|0644);
	printf("Id of message queue: %d\n",id);

//	msgctl(id, IPC_STAT, &mybuff);
	msgctl(id, IPC_RMID, NULL);

	// printing contents of message queue through struct msgid_ds
/*
	printf("Contents from the struct are: \n");
	printf("no of msges in queue: %hi\n",mybuff.msg_qnum);
	printf("no of bytes in queue: %hi\n",mybuff.msg_cbytes);
	printf("max no of bytes in queue: %hi\n",mybuff.msg_qbytes);
*/
	return 0;
}
