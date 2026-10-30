#include <stdio.h>
int main(){
	int arr[5];
	/*
	for(int i = 0; i<10; i++){
		arr[i] = i+1; // will cause an error saying bufer overflow and overwritting past allocated memory
		printf("%d", arr[i]);
	}
	*/

	for(int i = 0; i < 10; i++)
		printf(" %d", arr[i]);

	printf("\n");

	return 0;
}
