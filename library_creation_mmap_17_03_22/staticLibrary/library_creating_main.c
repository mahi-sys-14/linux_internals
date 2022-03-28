#include<stdio.h>
#include"calc_mean.h"

int main()
{
	double v1, v2, m1 , m2;

	v1=5.2;
	v2=7.9;

	m1 = mean(v1, v2);
	m2 = sub(v1, v2);

	printf("Mean of %3.3f & %3.3f is %3.3f\n",v1, v2, m1);
	printf("Substraction of %3.3f & %3.3f is %3.3f\n",v1, v2, m2);

	return 0;
}
