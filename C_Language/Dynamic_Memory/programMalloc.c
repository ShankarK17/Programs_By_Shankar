#include <stdio.h>
#include <stdlib.h>

int main(){
	int *ptr, n, i;
	printf("Enter number of elements to store: ");
	scanf("%d", &n);

	ptr = (int *)malloc(n * sizeof(int));
	if(ptr == NULL){
		printf("Required memory not available!\n");
		exit(1);
	}

	for(i = 0; i<n; i++){
		printf("Enter a value: ");
		scanf("%d", ptr+i);
	}

	for(i = 0; i<n; i++){
		printf("%d ", *(ptr+i));
	}

	printf("\n");

	return 0;
}
