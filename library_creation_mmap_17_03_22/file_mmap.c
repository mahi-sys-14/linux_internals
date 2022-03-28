#include<stdio.h>
#include<sys/mman.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	int fd;
	char *c;
	struct stat file_info;

	fd = open("kernel.txt", O_CREAT|O_RDWR, 0666); //perror(open);

	write(fd, "linux kernel technology", 25);

	fstat(fd, &file_info); //perror("fstat");
	printf("file size: %ld\n",file_info.st_size);

	c=mmap(0, file_info.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);  //msg success
	perror("mmap");

//	strcpy(c, "Mahima Vaghela"); //kernel region in U.S
	printf("%s\n",c);

	/* deallocate all resources */
	munmap(c, file_info.st_size); // malloc      after free

	close(fd);

	return 0;
}
