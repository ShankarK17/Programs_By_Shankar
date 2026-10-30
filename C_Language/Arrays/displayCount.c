#include <stdio.h>

int main(){
	int arr[] = {2, 6, 4, 3, 4, 7, 8, 2, 1, 5, 6, 8 , 9};
	int num, i, count = 0;
	printf("Enter the number to search and count it's occurance: ");
	scanf("%d", &num);

	int len = sizeof(arr) / sizeof(arr[0]);
	for(i = 0; i<len; i++){
		if(arr[i] == num)
			count++;
	}

	printf("The number %d occurs total of %d times in the array\n", num, count);

	return 0;

}
