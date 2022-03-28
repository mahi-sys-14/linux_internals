#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *name = (char *) alloca(10);

	strcpy(name, "Mahima Vaghela");

	printf("The string copied is: %s\n",name);

	return 0;
}
