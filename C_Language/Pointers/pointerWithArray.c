#include <stdio.h>
int main(){
	int arr[] = {1, 2, 3, 4, 5};

	int x, *ptr;
	ptr = arr;

	x = *ptr++;
	printf("After *ptr++ value of x = %d and current value in ptr = %d\n", x, *ptr);

	x = *++ptr;
	printf("After *++ptr new value of x = %d and current value in ptr = %d\n", x, *ptr);

	x = ++(*ptr);
	printf("After ++*ptr new value of x = %d and current value in ptr = %d\n", x, *ptr);

	x = (*ptr)++;
	printf("After (*ptr)++ new value of x = %d and current value in ptr = %d\n", x, *ptr);

	printf("After this operations the array is : ");
	for(int i = 0; i<5; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}

