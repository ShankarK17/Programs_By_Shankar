#include <stdio.h>
#define SIZE 5
int main(){
	int arr[SIZE] = {1, 2, 3, 4, 5};
	int d;
	

	for(int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);

	printf("\n");
	printf("Enter position of element to be removed: ");
	scanf("%d", &d);

	for(int i = d-1; i < SIZE; i++)
		arr[i] = arr[i+1];
			
	arr[SIZE - 1];

	for(int j = 0; j<SIZE-1; j++)
		printf("%d ", arr[j]);
	
	printf("\n");

	return 0;
}

