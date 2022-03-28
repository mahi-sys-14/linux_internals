#include<stdio.h>
#include<string.h>

struct student
{
	int roll_no;
	char name[20], gender;
	float height;
}first;
/*
struct A
{
	int roll;
	char gender __attribute__((aligned(2)));
	float height;
}__attribute__((packed));
*/
struct A
{
	int roll;
//	char gender;
	float height;
};

int main()
{
	struct student second;
	struct student third = {10, "Mahima Vaghela", 'F', 5.3};

	first.roll_no = 9;
	strcpy(first.name , "Rohan Vaghela");
	first.gender = 'M';
	first.height = 6.1;

	printf("First \nID: %d \t name: %-40s \t gender: %c \t height: %1.2f\n",first.roll_no, first.name, first.gender, first.height);	
	printf("Third \nID: %d \t name: %s \t gender: %c \t height: %1.2f\n",third.roll_no, third.name, third.gender, third.height);	

	printf("Size of structure: %ld\n", sizeof(struct student));
	printf("Size of structure: %ld\n", sizeof(struct A));

	return 0;
}
