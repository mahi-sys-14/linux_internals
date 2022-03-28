#include<stdio.h>
#include<unistd.h>

int main()
{
	long int page_size = sysconf(_SC_PAGESIZE);
	printf("my page size: %ld\n", page_size);

	void *c1 = sbrk(0);				// returning the current end address of the program data segment
	printf("program btreak address: %p\n",c1);
	printf("Size of character: %lu\n",sizeof(char));

	c1 = (void *) ((char *) c1 + 9);		// adding 9 to the current program data segment: incrementing it by 9
	printf("c1: %p\n",c1);

	brk(c1);					// setting new break point by passing the updated address

	void *c2 = sbrk(0);				// return the new address of break point or end address of program data segment
	printf("program break address: %p\n",c2);


	return 0;
}
