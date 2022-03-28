#include<stdio.h>
#include<sys/mman.h>
#include<string.h>

int main()
{
	char *c;

	c=mmap(0, 50, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);  //msg success
	perror("mmap");

	strcpy(c, "Mahima Vaghela"); //kernel region in U.S
	printf("%s\n",c);

	/* deallocate all resources */
	munmap(c, 50); // malloc      after free

	return 0;
}
