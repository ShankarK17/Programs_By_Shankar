#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char str[100];
	fp = fopen("Quote.txt", "w");
	if(fp == NULL){
		printf("Couldn't open file!");
		exit(1);
	}
	printf("Enter text here: ");
	while(1){
		fgets(str, 100, stdin);
		if(str[0] == '\n')
			break;
		fputs(str, fp);
	}
	fclose(fp);

	printf("Reading the file:\n");
	fp = fopen("Quote.txt", "r");
	if(fp == NULL){
		printf("Couldn't load the file!");
		exit(1);
	}

	while(fgets(str, 100, fp) != NULL){
		printf("%s", str);
	}
	fclose(fp);

	return 0;
}
