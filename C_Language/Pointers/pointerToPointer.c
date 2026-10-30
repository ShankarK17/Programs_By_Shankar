#include <stdio.h>

int main(){
	int a = 5, *p = &a, **pp = &p;

	printf("value of a via pointer to int = %d\n", *p);
	printf("address of a via pointer = %u\n", p);
	printf("address of p = %u\n", &p);
	printf("address of pointer via pointer to pointer = %u\n", pp);
	printf("value of a via pointer to pointer to int = %d\n", **pp);
	printf("value of pp = %u\n", pp);
	printf("address of pp = %u\n", &pp);

	return 0;
}

