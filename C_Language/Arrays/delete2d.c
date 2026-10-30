#include <stdio.h>
#define ROW 3
#define COL 3
int main(){
	int arr[ROW][COL];
	int dr, dc ;
	int i,j;
	for(i = 0; i<ROW; i++){
		for(j = 0; j<COL; j++){
			printf("Enter element at arr[%d][%d]: ", i+1, j+1);
			scanf("%d", &arr[i][j]);
		}
	}

	for(int k = 0; k<ROW; k++){
	       for(int l= 0; l<COL; l++)
	       		printf("%d ", arr[k][l]);
		printf("\n");
	}		

	printf("Enter row & col of the element to be removed:  ");
	scanf("%d %d", &dr, &dc);

	int removed = arr[dr-1][dc-1];

	for(i = dr-1; i<ROW; i++){
		for(j = dc-1; j<COL; j++){
			arr[i][j] = arr[i][j+1];
		}
		break;
	}


	printf("After removing %d from the Martix(2-D array): \n", removed);
	for(i = 0; i<ROW; i++){
		if(i == dr-1){
			for(j=0; j<COL-1; j++){
				printf("%d ", arr[i][j]);
			}
		}
		else{
			for(j = 0; j<COL; j++)
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}


