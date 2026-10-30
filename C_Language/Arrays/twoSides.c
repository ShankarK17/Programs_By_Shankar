#include <stdio.h>
int main(){
	int arr[8] = {2, 3, 7, 5, 5, 7, 5, 2};

	for(int i = 0; i<8/2; i++){
		if(arr[i] == arr[8 - (i+1)])
			printf("true ");
		else
			printf("false ");
	}

	printf("\n");
	return 0;
}

