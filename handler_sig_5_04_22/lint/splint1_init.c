#include<stdio.h>

const char *into_string(int value)
{
	const char *ret;

	switch(value)
	{
		case 1:
			ret = "one";
			break;
		case 2:
			ret = "two";
			break;
		case 3:
			ret = "three";
			break;
		default:
			ret = "less than 1 or more than 3";
			break;
	}

	return ret;
}

int main()
{
	int i=25;

	printf("into_string(2) = %s\n",(char *)into_string(2));

	return 0;
}

/*
#include<stdio.h>

int main()
{
	int i;

	printf("i is: %d\n",i);

	i=25;
	if(i=25)
		printf("value is 25\n");

	return 0;
}
*/

