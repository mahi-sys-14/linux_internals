#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Using ls command program\n");

//	execl("/usr/bin/vim", "vim", "info.txt", 0);
	execl("/home/mahima/mahima/linux_internals/9_03_22/fork_prb", "./fork_prb", 0);

	printf("Executing ls\n");
	printf("Executing ls\n");
	printf("Executing ls\n");

	return 0;
}
