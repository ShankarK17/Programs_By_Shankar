#include <stdio.h>
int main(){
	int arr[] = {1, 2, 3, [1] = 7, 5, 6, [4] = 18, [17] = 71};

	printf("size of array = %ld\n", sizeof(arr));
	for(int i = 0; i<(sizeof(arr)/sizeof(arr[0])); i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}
