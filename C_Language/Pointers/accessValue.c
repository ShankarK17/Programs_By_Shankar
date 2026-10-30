#include <stdio.h>

int main(){
	int x = 5;
	int *ptr = &x;

	printf("The value of x = %d\n", x);
	printf("The value of x through ptr = %d\n", *ptr);
	printf("The value of x through address of x = %d\n", *(&x));
	printf("The address of x = %u\n", &x);
	printf("The address of x through pointer = %u\n", ptr);
	printf("The address of ptr = %u\n", &ptr);
	*ptr = 9;
	printf("The value of x after modifying it via ptr = %d\n", x);

	return 0;
}
