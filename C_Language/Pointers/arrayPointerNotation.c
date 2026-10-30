#include <stdio.h>

int main(){
	int arr[] = {5, 6, 7, 8, 9};
	for(int i = 0; i<5; i++)
		printf("Value of arr[%d]: %d\t Address of arr[%d]: %u\n",i, *(arr+i), i, (arr+i));

	return 0;
}
