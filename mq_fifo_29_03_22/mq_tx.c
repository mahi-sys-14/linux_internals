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
/*	if(argc != 3)
	{
		printf("usage..../mq_tx msg_type data\n");
		printf("Example: mq_tx 5 \"hello\" \n");
		return 0;
	}*/

	id = msgget(55, IPC_CREAT|0644);
/*	if(id < 0)
	{
		perror("msgget"); 	/// ./mq_tx 12 linux\0
		return 0;
	}*/

	printf("Id of message queue: %d\n",id);
	v.mtype = atoi(argv[1]);	// "12"		// argument 1 is type of messge converting ascii to int
	strcpy(v.buff, argv[2]);	// arg 2 is message

	msgsnd(id, &v, strlen(v.buff) +1, 0); // flag: IPC_NOWAIT
	//perror("msgsnd");		// "./wrt" "type" "data"

	return 0;
}
