#include <stdio.h>
#define SIZE 6
int main(){
	int arr[SIZE] = {1, 2, 3, 4, 5, 6};
	int *ptr1 = &arr[0];
	int *ptr2 = &arr[SIZE - 1];

	printf("The lenght of array is %d\n", (ptr2 - ptr1) + 1);

	return 0;
}
