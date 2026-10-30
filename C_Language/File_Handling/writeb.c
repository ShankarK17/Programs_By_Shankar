#include <stdio.h>
#include <stdlib.h>

int main(){
	struct car {
		char model[20];
		int year;
	} c;

	FILE *fp;
	fp = fopen("cars.data", "wb");
	if(fp == NULL){
		printf("Error while opening the file!");
		exit(1);
	};
	int n, i;
	printf("Enter number of records of cars to be entered: ");
	scanf("%d", &n);

	for(i = 0; i<n; i++){
		printf("Enter the details of the car: ");
		scanf("%s %d", c.model, &c.year);
		fwrite(&c, sizeof(c), 1, fp);
	}

	fclose(fp);

	return 0;
}
