#include <stdio.h>
int main(){
	int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
/*
	printf("The value of *(arr): %u\n", *(arr+0));
	printf("The value of *(arr+1): %u\n", *(arr+1));
	printf("The value of *(arr+2): %u\n", *(arr+2));
*/
	int (*a)[4] = arr;
	printf("The value of *(arr+1): %ls\n", *(arr+1));
	printf("The value of *(*(arr+1)): %ld\n", *(*(arr+1)));
	printf("%ld\n",*(arr+1)+1 );	
	printf("The value of *(*(arr+1)+1): %ld\n", *(*(arr+1)+1));

	printf("%d", *(*(a+0)+1));
	printf("%d", *(*(a+1)+2));
	printf("%d", *(*(a+2)+3));
	return 0;
}
