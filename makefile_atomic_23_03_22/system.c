#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buff[10];
	int ret;

//	strcpy(buff, "ls -l");
	strcpy(buff, "NULL");

	printf("system() library function uses fork() to create a child process\n");
	printf("child process executes execl() which loads and run new program provided by system() arguments\n");

	ret = system(buff);
	printf("system() returning: %d\n",ret);

	return 0;
}
