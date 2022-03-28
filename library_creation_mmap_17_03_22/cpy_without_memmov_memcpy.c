#include<stdio.h>

void *mymemcopy(char *src, char *dest, size_t bytes)
{
	for(int i=0; i<bytes; i++)
	{
//		dest[i] = src[i];
		*dest = *src;
		dest++;
		src++;
	}

}

int main()
{
	char src[] = "User defined function, to copy from source to destination, which is second arg";
	char dest[200];

	mymemcopy(src, dest, sizeof(src));

	printf("After copying destination string: %s\n",dest);

	return 0;
}
