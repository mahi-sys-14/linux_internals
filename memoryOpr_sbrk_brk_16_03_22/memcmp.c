#include<stdio.h>
#include<string.h>

int main()
{
	char buff1[50], buff2[50];
	int ret;

	memcpy(buff1, "madam", 6); //madam----97(----109
	memcpy(buff2, "mad", 6); // mad----65----77

	ret = memcmp(buff1, buff2, 6);

	if(ret > 0)
		printf("buff1 is greater than buff2\n");
	else if(ret < 0)
		printf("buff1 is lesser than buff2\n");
	else
		printf("both the buffer data is same\n");

	return 0;
}

