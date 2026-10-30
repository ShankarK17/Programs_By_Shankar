#include <stdio.h>
void findmin(int *, int);
int main(){
	int arr[] = {2, 9, 15, 37, 5, 60, 81, 40, 93};
	int len = sizeof(arr) / sizeof(arr[0]);

	int min ,max;
	min = max = arr[0];

	for(int i = 1; i<len; i++){
		if(arr[i] > max)
		       max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}

	printf("min: %d & max: %d", min, max);

	return 0;
}

	
