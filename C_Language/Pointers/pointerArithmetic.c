#include <stdio.h>
int main(){
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	int *ptr = &arr[0];
	int *ptr2 = &arr[7];
	printf("Value at pointer: %d\n", *ptr);
	ptr = ptr + 3;
	printf("Value at pointer: %d\n", *ptr);

	ptr--;
	printf("Value at pointer: %d\n", *ptr);

	printf("The distance/elements between two pointers is %ld\n", ptr2 - ptr);

	return 0;
}


