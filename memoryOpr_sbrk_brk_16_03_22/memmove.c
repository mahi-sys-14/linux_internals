#include<stdio.h>
#include<string.h>

int main()
{
	char dest[] = "oldstring";
	const char src[] = "newstring";

	printf("before memmove dest: %s & src: %s\n",dest, src);
	memmove(dest, src, 2);

	printf("after memmove dest: %s & src: %s\n",dest, src);


	return 0;
}
