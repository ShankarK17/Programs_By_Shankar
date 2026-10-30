#include <stdio.h>

int main(){

	int i, n = 10;
	int arr[n];
	int pos = 0, neg = 0, even = 0, odd = 0;
	printf("Enter 10 elements of an array: ");
	for(i = 0; i<10; i++)
		scanf("%d", &arr[i]);

	for(i = 0; i < 10; i++){
		if(arr[i] >= 0){
			pos++;
			if(arr[i] % 2 == 0)
				even++;
			else
				odd++;
		}
		else{
			neg++;
			if(arr[i] * -1 % 2 == 0)
				even++;
			else
				odd++;
		}

	}

	printf("Total Number of elements %d out of which: \n", n);
	printf("%d are positive, %d are negative, %d are even & %d are odd.\n", pos, neg, even, odd);

	return 0;
}
