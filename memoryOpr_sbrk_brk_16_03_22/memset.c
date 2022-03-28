#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "Linux kernel file memset";
	const char ch = '#';

	printf("string before set: %s\n",str);
	
//	memset(str, ch, strlen(str)); //func & array....name itself is addr
	memset(str, ch, 5); //func & array....name itself is addr

	
	printf("string after set: %s\n",str);

	return 0;
}
