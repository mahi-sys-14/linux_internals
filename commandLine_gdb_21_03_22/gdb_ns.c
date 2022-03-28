#include<stdio.h>
#include<string.h>

void myprint(char *msg)
{

	if(msg != NULL)
		printf("Msg is : %s\n",msg);
}

int main()
{
	char buff[] = "linux";

	myprint(buff);

	return 0;
}
