#include <stdio.h>
void fun2d(int (*)[]);
int main(){
	int arr[3][4] = {{1, 2, 3, 4},
			 {5, 6, 7, 8},
			 {9, 10, 11, 12}};

	printf("Size of arr[3][4]: %ld\n", sizeof(arr));
	for(int i = 0; i<3; i++){
		for(int j = 0; j<4; j++)
			printf("%d ", arr[i][j]);

		printf("\n");
	}

	printf("arr after passing in function: \n");
	fun2d(arr);

	return 0;
}
void fun2d(int (*a)[4]){
	for(int i = 0; i<3; i++){
		for(int j = 0; j<4; j++){
			a[i][j] = a[i][j] * 2;
			printf("%d ", a[i][j]);
		}
		printf("\n");

	}
	printf("size of a: %ld\n", sizeof(a));
	printf("size of *a: %ld\n", sizeof(*a));
}



