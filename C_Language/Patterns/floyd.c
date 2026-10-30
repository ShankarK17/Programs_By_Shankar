// PROGRAM TO PRINT FLOYD RIGHT-ANGLED TRIANGLE
#include <stdio.h>
int main(){
	int n = 5, count = 1;

	for(int row = 1; row <= n ; row++){
		for(int col = 1; col <= row; col++){
			printf("%d ",count);
			count++;
		}
		printf("\n");
	}

	return 0;
}
