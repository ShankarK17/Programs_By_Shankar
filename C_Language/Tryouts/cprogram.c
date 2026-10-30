#include <stdio.h>

int main(){
	int arr[][3] = {{'1', '2', '3'},
		     {'A', 'B', 'C'}};
	*(*(arr+1)+1) = 'Z';
	int len =  sizeof(arr)/sizeof(**arr);
	int *ptr = *arr;

	for(int i = 0; i<2; i++){
		for(int j = 0; j<3; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	while(len > 0){
		printf("%c ", *ptr++);
		len--;
	}

	

	return 0;
}
