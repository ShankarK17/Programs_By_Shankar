// Passing an element of array to a function by call by value and call by reference
#include <stdio.h>
void byvalue(int);
void byreference(int *);

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	
	for(int i = 0; i < 5; i++)
		byvalue(arr[i]);

	printf("\n");

	for(int j = 0; j < 5; j++)
		byreference(&arr[j]);
	
	printf("\n");
	return 0;
}

void byvalue(int a){
	printf("%d ", a);
}

void byreference(int *b){
	printf("%d ", *b);
}

