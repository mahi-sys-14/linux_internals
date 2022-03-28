#include<stdio.h>
#include<stdlib.h>

void buggy(int *p)
{
	p[0] = 10;
	free(p);
}

int main()
{
	int *ptr;

	ptr =(int *) malloc(4);
	buggy(ptr); // 2. passing addr of 4 bytes to through a ptr
	free(ptr); // 6. double free i.e. trying to free a ptr already freed
			// error

	return 0;
}
