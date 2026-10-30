#include <stdio.h>

int main(){
	//int arr[5] = {128, 255, 57};
/*
	for(int i = 0; i<5; i++)
		printf("%d ", arr[i]);
*/
	//printf("%d\n", *(arr + 1));
	int size = 5;
	int arr[size];

	arr[0] = 0;

	for(int i = 0; i<size; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
