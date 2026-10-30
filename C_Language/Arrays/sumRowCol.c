#include <stdio.h>
#define SIZE 5
int main(){
	int arr[SIZE][SIZE];
	int i,j;

	for(i = 0; i<SIZE; i++){
		for(j = 0; j<SIZE; j++)
			scanf("%d", &arr[i][j]);

	}

	int rowSum = 0, colSum = 0;
	printf("Row Sum: ");
	for(i = 0; i<SIZE; i++){
		for(j = 0; j<SIZE; j++){
			rowSum += arr[i][j];
		}
		printf("%d ", rowSum);
		rowSum = 0;
	}

	printf("\n");
	printf("Column Sum: ");
	for(i = 0; i<SIZE; i++){
		for(j = 0; j<SIZE; j++){
			colSum += arr[j][i];
		}
		printf("%d ", colSum);
		colSum = 0;
	}

	printf("\n");

	return 0;
}

