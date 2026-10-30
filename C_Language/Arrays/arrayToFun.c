#include <stdio.h>
void changeEle(int []);
int main(){
	int arr[5] = {1, 2, 3, 4, 5};

	changeEle(arr);

	for(int j = 0; j < 5; j++)
		printf("%d ", arr[j]);

	printf("\n");
	return 0;

}

void changeEle(int num[]){
	for(int i = 0; i<5; i++)
		num[i] = num[i] * num[i];

}

