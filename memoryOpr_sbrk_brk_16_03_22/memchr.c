#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "Linux kernel file-memset";
	const char ch = '-';
	char *ret;

	printf("string before set: %s\n",str);
	
	ret = memchr(str, ch, strlen(str)); //func & array....name itself is addr
//	memchr(str, ch, 5); //func & array....name itself is addr

	
	printf("string after %c==>> %s\n",ch,ret-1);

	return 0;
}
