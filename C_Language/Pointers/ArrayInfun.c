#include <stdio.h>
void defsize(int [], float *, char []);
int main(){
	int arr1[] = {1, 2, 3, 4, 5};
	float arr2[3] = {1.1, 2.2, 3.3};
	char arr3[3] = {'a', 'b', 'c'};

	printf("size of integer array: %ld\n", sizeof(arr1));
	printf("size of floar array: %ld\n", sizeof(arr2));
	printf("size of character array: %d\n", sizeof(arr3));
	
	defsize(arr1, arr2, arr3);
	return 0;

}
void defsize(int a[], float *b, char c[3]){
	printf("size of integer array a for arr1: %ld\n", sizeof(a));
	printf("size of pointer varaible b for arr2: %ld\n", sizeof(b));
	printf("size of character array c for arr3: %ld\n", sizeof(c));

}
