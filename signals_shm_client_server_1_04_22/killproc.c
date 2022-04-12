#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int i, sig_no;

	printf("Enter the pid of the process for which the signal need to be sent:\n");

	scanf("%d", &pid);

	printf("Enetr the signal that need to be sent: ");
	scanf("%d", &sig_no);

	kill(pid, sig_no);
	perror("sig_rest");

	return 0;
}
