#include<stdio.h>
#include<errno.h>
#include<unistd.h>

int main()
{
	int ret, i, count=0;
	errno=0;
	ret = nice(1);

	if(ret == -1 && errno!=0)
		perror("nice");
	else
		printf("NIce value is : %d\n",ret);

	while(1)
	{
		printf("Process with nice value: %d and count=%d\n",ret, count);
		for(int i=0; i<10000000; i++)
			count++;
	}

	return 0;
}
