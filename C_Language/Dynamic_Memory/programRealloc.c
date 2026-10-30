#include <stdio.h>
#include <stdlib.h>

int main(){
	float *fp;
	int n, i;
	printf("Enter size: ");
	scanf("%d", &n);

	fp = (float *)calloc(n , sizeof(float));

	if(fp == NULL){
		printf("Sufficient memory not available!\n");
		exit(1);
	}

	for(i = 0; i<n; i++){
		printf("Enter a float value: ");
		scanf("%f", fp+i);
	}

	printf("Enter new size: ");
	scanf("%d", &n);

	fp = (float *)realloc(fp, n*sizeof(float));
	if(fp == NULL){
		printf("Specified memory not available!\n");
		exit(1);
	}

	for(i; i<n; i++){
		printf("Enter new value: ");
		scanf("%f", fp+i);
	}

	for(i = 0; i<n; i++)
		printf("%f ", *(fp+i));

	return 0;
}
