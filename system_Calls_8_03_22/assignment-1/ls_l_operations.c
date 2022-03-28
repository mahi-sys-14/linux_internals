#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	struct stat st; //st.st_size st.st_ino st.st_blksize
	int fd;

//	fd=open("que3.txt", O_CREAT | O_RDWR, 0666);
//	fstat(fd, &st);

	stat("file.txt", &st);

	printf("File size = %lu\n",(st.st_size)); //ls -l file.txt
	printf("File inode = %lu\n",(st.st_ino)); //ls -i file.txt
	printf("File group id = %u\n",(st.st_gid)); //ls -l file.txt
	printf("File user id  = %u\n",(st.st_uid)); //ls -l file.txt
	printf("File mode = %u\n",(st.st_mode)); //ls -l file.txt

	printf("size disc of blocks = %lu\n",(st.st_blksize)); //stat -fc %s file.txt
	printf("File data's last access time = %lu\n",(st.st_atime)); //ls -l file.txt
	printf("File's last modification time = %lu\n",(st.st_mtime)); //ls -l file.txt
	printf("time of last change to the inode = %lu\n",(st.st_ctime)); //ls -l file.txt


	return 0;
}
