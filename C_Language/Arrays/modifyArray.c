#include <stdio.h>

int *modify(int []);

int main(){
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	printf("size of arr: %ld\n", sizeof(arr));
	int *new = modify(arr);

	for(int i = 0; i <=9; i++){
		printf("%d ", *new);
		new++;
	}
	printf("\n");

	return 0;
}

int *modify(int num[]){
	printf("size of num: %ld\n", sizeof(*num));
	for(int i = 0; i<10; i++)
		num[i] *= 3;

	return num;

}

