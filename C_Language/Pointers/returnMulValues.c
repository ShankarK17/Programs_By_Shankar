#include <stdio.h>

void func(int [], int);

int main(){

	int value, size;
	printf("Enter number of elements to add in array: ");
	scanf("%d", &size);

	int arr[size];

	func(arr, size);

	for(int j = 0; j<size; j++)
		printf("%d ", arr[j]);

	printf("\n");

	return 0;
}

void func(int a[], int n){
	int i, ele;
	for(i = 0; i<n; i++){
		printf("Enter number%d: ", i+1);
		scanf("%d", &ele);
		a[i] = ele;
	}

}


