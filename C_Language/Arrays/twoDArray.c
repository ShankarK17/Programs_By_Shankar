#include <stdio.h>
#define ROW 3
#define COL 4

int main(){
	int arr[ROW][COL];

	for(int i = 0; i<ROW; i++){
		for(int j = 0; j<COL; j++)
			scanf("%d", &arr[i][j]);
		
	}

	for(int i = 0; i<ROW; i++){
		for(int j = 0; j<COL; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
	
