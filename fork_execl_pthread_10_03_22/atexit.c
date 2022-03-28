#include<stdio.h>

void callback1()
{
	printf("Calling callback1\n");
}

void callback2()
{
	printf("Calling callback2\n");
}

void callback3()
{
	printf("Calling callback3\n");
}

int main()
{
	printf("Registering callback1\n");
	atexit(callback1);
	printf("Registering callback2\n");
	atexit(callback2);
	printf("Registering callback3\n");
	atexit(callback3);

	_exit(0);
//	return 0;
}
