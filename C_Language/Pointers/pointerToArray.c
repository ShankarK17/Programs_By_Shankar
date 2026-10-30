#include <stdio.h>

int main(){
	unsigned int arr[3] = {5, 6, 7};

	unsigned int *p = arr;
	unsigned int (*ptr)[3] = &arr;

	printf("value of p = %u\n", p);
	printf("value of pa = %u\n", ptr);
	printf("value at p = %d\n", *p);
	printf("value at pa = %u\n", *ptr);

	p++; ptr++;

	printf("value of p++: %u\n", p);
	printf("value of ptr++: %u\n", ptr);
	printf("value at p++: %d\n", *p);
	printf("value at ptr++: %u\n", *ptr);

	printf("size of p: %d & size of *p: %d\n", sizeof(p), sizeof(*p));
	printf("size of ptr: %d & size of *ptr: %d\n", sizeof(ptr), sizeof(*ptr));


	return 0;
}
