#include <stdio.h>
#include <string.h>

int main(){
	typedef enum role{
		trainee, associate, senior
	} ROLE;

	typedef struct employee {
		char name[20];
		int age;
		ROLE r;
		
	} EMP;

	EMP e1;
	printf("Enter your Details: ");
	scanf("%s %d", e1.name, &e1.age);
	e1.r = senior;

	printf("Name: %s\t Age: %d\t Profile: %d\n", e1.name, e1.age, e1.r);

	return 0;
}

