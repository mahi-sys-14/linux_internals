#include<stdio.h>
#include<sys/msg.h>
#include<sys/types.h>
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

	printf("MESSAGE ID: %d\n",mqid);

	msgrcv(mqid, &mb, sizeof(mb), 12 , 0);
	printf("Message received: %s\n",mb.data);

	return 0;
}	
