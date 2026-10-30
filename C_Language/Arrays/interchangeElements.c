//program to interchange element of array with odd places to even places
#include <stdio.h>
int main(){
	int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

	printf("Elements of array before interchangng:- \n");
	for(int i = 0; i<10; i++)
		printf("%d ", arr[i]);

	printf("\n");
	int i, temp;
	for(i=0; i<9; i=i+2){
		temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
	}

	printf("After interchanging the elements the array- \n");
	for(int i = 0; i<10; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}


