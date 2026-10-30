#include <stdio.h>
int main(){
	int arow, acol, brow, bcol;
	printf("Enter rows and columns for Matrix 1: ");
	scanf("%d %d", &arow, &acol);
	printf("Enter rows and columns for Matrix 2: ");
	scanf("%d %d", &brow, &bcol);
	if(acol != brow || acol == 0 || brow == 0){
		printf("The multiplication is not possible");
		return 1;
	}
	int i,j, sum = 0;
	int a1[arow][acol];
	int a2[brow][bcol];
	int ar[acol][brow];
	printf("Enter elements of arr1: \n");
	for(i = 0; i<arow; i++){
		for(j = 0; j<acol; j++)
			scanf("%d", &a1[i][j]);
	}
	printf("Enter elements for arr2: \n");

	for(i = 0; i<brow; i++){
		for(j = 0; j<bcol; j++)
			scanf("%d", &a2[i][j]);
	}

	for(i = 0; i<arow; i++){
		for(j = 0; j<bcol; j++){
			for(int k = 0; k<brow; k++)
				sum += a1[i][k] * a2[k][j];
		ar[i][j] = sum;
		sum = 0;
		}
	}
	
	printf("The resultant array is: \n");
	for(i = 0; i<arow; i++){
		for(j = 0; j<bcol; j++)
			printf("%d ", ar[i][j]);
		printf("\n");
	}

	return 0;
}

