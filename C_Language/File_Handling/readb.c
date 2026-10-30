#include <stdio.h>
#include <stdlib.h>

int main(){
	struct car{
		char model[20];
		int year;
	} c;

	FILE *fp;
	fp = fopen("cars.data", "rb");
	if(fp == NULL){
		printf("Error while loading the file");
		exit(1);
	};
	printf("Car Model\tYear of Manufacturing\n");
	while(fread(&c, sizeof(c), 1, fp)){
		printf("%s\t", c.model);
		printf("%15d\n", c.year);
	};
	fclose(fp);
	return 0;
}

