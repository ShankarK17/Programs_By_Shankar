#include <stdio.h>
#define MY_SIZEOF(x) ((char *)(&x + 1) - ((char *)(&x)))

int main(){
	int a = 4;
	float b = 1.1f;
	char c = 's';

	int arr[] = {1, 2, 3, 4, 5};

	printf("The size of integer variable a = %ld\n", MY_SIZEOF(a));
	printf("The size of float variable b = %ld\n", MY_SIZEOF(b));
	printf("The size of character variable a = %ld\n", MY_SIZEOF(c));
	printf("The size of array arr = %ld\n", MY_SIZEOF(arr));

	return 0;
}
