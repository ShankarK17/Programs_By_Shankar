#include <stdio.h>
struct minor {
	char gender;
	int age;
};
struct major {
	char gender;
	int age;
	char status;
};

int main(){
	union person{
		struct minor m1;
		struct major m2;
	} p1;

	printf("Size of union: %ld\n", sizeof(p1));

	printf("Assigning person Minor:-\n");
	p1.m1.gender = 'm';
	p1.m1.age = 15;

	printf("Value of p1.gender: %c\t", p1.m1.gender);
	printf("Value of p1.age: %d\n", p1.m1.age);
	printf("Value of p2.gender: %c\t", p1.m2.gender);
	printf("Value of p2.age: %d\t", p1.m2.age);
	printf("Value of p2.status: %c\n", p1.m2.status);
	printf("\n");
	printf("Assigning person Major:-\n");
	p1.m2.gender = 'f';
	p1.m2.age = 22;
	p1.m2.status = 's';

	printf("Value of p1.gender: %c\t", p1.m1.gender);
	printf("Value of p1.age: %d\n", p1.m1.age);
	printf("Value of p2.gender: %c\t", p1.m2.gender);
	printf("Value of p2.age: %d\t", p1.m2.age);
	printf("Value of p2.status: %c\n", p1.m2.status);

	printf("\n");

	return 0;
}


