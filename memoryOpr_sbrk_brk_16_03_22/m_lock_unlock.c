#include<stdio.h>
#include<string.h>

int main()
{
	size_t i;
	const int alloc_size = 32 *1024 * 1024;

	//const int alloc_size = 320;
	char *memory = malloc(alloc_size);

	mlock(memory, alloc_size);

	// size_t page_size = getpagesize();
	for(i=0; i <alloc_size; i++)
		memory[i] = '#';

	printf("Allocated memory initialized with: %s\n", memory);

	munlock(memory, alloc_size);

	return 0;
}
