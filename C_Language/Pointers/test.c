#include <stdio.h>
int main(){
	/*
	int arr[] = {1, 2, 3};
	int *p = arr;
	printf("The address of first element: %u\n", arr);
	printf("The address of first elment: %u\n", &arr[0]);
	printf("The value of 2nd elment: %d\n", *(arr+1) );

	int i = 2;
	printf("The value = %d", p[i]);
	*/
	unsigned int i = 5;
	unsigned int *ptr = &i;

	printf("d = %d \n",(int) ptr);
	printf("u = %u \n", ptr);
	printf("ls = %ls \n", ptr);
	printf("ptr = %d  \n", sizeof(ptr));
	printf("i = %lu  \n", sizeof(i));

	return 0;
}
