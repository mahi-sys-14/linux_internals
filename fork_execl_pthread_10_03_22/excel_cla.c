#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("command line arguments program\n");

//	execl("/usr/bin/vim", "vim", "info.txt", 0);
	execl("/home/mahima/mahima/linux_internals/9_03_22/command_line_arg_execl", "./command_line_arg_execl", "mahima", "linux", 0);
/*
	printf("Executing ls\n");
	printf("Executing ls\n");
	printf("Executing ls\n");
*/
	return 0;
}

