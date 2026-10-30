#include <stdio.h>

int main(){
	int arr[5], rev[5];
	printf("Enter elements for array 1:- \n");
	for(int i = 0; i<=4; i++){
		scanf("%d", &arr[i]);
	}

	int j,k;

	for(j = 4,k = 0; j >=0; j--,k++)
		rev[k] = arr[j];

	printf("The reverse array: ");
	for(int j = 0; j<5; j++)
		printf("%d ", rev[j]);

	printf("\n");

	return 0;
}
