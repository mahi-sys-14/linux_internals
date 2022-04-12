#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

//#define KEY 8979

typedef struct msg_buf
{
	long mtype;
	char buff[512];
}msg;

int main(int argc, char *argv[])
{
	msg v1, v2;

	int id, i;

	id = msgget(32, IPC_CREAT|0644);
/*	if(id < 0)
	{
		perror("msgget"); 	/// ./mq_tx 12 linux\0
		return 0;
	}*/

	printf("Id of message queue: %d\n",id);

	v1.mtype = 1;	// "1"
	for(i=0; i<100; i++)
		v1.buff[i] = 'a';

//	strcpy(v1.buff, "hello girl");	

	v2.mtype = 2;	// "2"	
	for(i=0; i<100; i++)
		v2.buff[i] = 'z';

//	strcpy(v2.buff, "byee byee");

	i = msgsnd(id, &v1, strlen(v1.buff) +1, 0); // flag: IPC_NOWAIT
	//perror("msgsnd");		// "./wrt" "type" "data"
	printf("return value of msgsnd v1: %d\n",i);

	i = msgsnd(id, &v2, strlen(v2.buff) +1, 0); // flag: IPC_NOWAIT
	printf("return value of msgsnd v2: %d\n",i);

	return 0;
}
