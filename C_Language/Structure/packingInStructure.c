#include <stdio.h>
struct emp{
	char name[30];
	int age;
	float salary;
} e1;


int main(){
	printf("%ld\n", sizeof(e1));
	printf("Char Array address emp1 = %u\tInt Address = %u\tFloat address = %u\n", e1.name, &e1.age, &e1.salary);

	//printf("Char Array address emp2 = %u\tInt Address = %u\tFloat address = %u\n", e2.name, &e2.age, &e2.salary);

	return 0;
}
