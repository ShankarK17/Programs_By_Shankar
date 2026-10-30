#include <stdio.h>
#include <stdlib.h>

int main(){
	int **pp, i, j, row, col;
	printf("Enter rows & columns of 2d Array: ");
	scanf("%d %d", &row, &col);

	pp = (int **)malloc(row*sizeof(int *));
	if(pp == NULL){
		printf("Specified memory not available!\n");
		exit(1);
	}

	for(i = 0; i<row; i++){
		pp[i] = (int *)malloc(col*sizeof(int));
		if(pp[i] == NULL){
			printf("Required memory space not available!");
			exit(1);
		}
	}

	for(i = 0; i<row; i++){
		for(j = 0; j<col; j++){
			printf("Enter element of array at [%d][%d]: ", i, j);
			scanf("%d", &pp[i][j]);
		}
	}

	printf("The 2d Array is:-\n");
	for(i = 0; i<row; i++){
		for(j = 0; j<col; j++){
			printf("%d ", pp[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i<row; i++)
		free(pp[i]);
	free(pp);



	return 0;
}
