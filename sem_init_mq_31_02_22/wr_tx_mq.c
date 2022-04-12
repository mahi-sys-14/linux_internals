#include<stdio.h>
#include<sys/msg.h>
//#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/stat.h>

struct mybuff
{
	long type;
//	double type;
	char data[512];
};

int main()
{
	int mqid;
//	char *buff_snd;
	struct mybuff mb;

	mqid = msgget(44, IPC_CREAT|0644);
	if(mqid < 0)
	{
		perror("msgget"); 	/// ./mq_tx 12 linux\0
		return 0;
	}

	printf("MESSAGE ID: %d\n",mqid);

	mb.type = 12;
	strcpy(mb.data, "Hello 31-03-22");

	msgsnd(mqid, &mb, strlen(mb.data)+1, 0);

	return 0;
}	
