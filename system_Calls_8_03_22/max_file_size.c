#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

	printf("MAx file size: %d\n",getdtablesize()); //will get fd table size

return 0;
}
