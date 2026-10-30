#include <stdio.h>
int *findmin(int *, int [], int);

int main(){
	int arr[7] = {89, 93, 1, 15, 6, 77, 3};
	int *min = &arr[0];

	min = findmin(min, arr, 7);

	printf("The smallest value in array is %d\n", *min);

	return 0;
}

int *findmin(int *low, int num[], int n){
	int i = 1;
	while(i < n){
		if(num[i] < *low)
			*low = num[i];
		
	i++;
	}

	return low;
}

