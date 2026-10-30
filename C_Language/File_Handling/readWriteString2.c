#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char str[100];
	fp = fopen("Quote1.txt", "w");
	if(fp == NULL){
		printf("Couldn't open file!");
		exit(1);
	}
	printf("Enter text here: ");
	scanf(" %[^\n]s", str);

	fputs(str, fp);
	fputs("\0", fp);
	fclose(fp);

	printf("Readind the file:\n");
	fp = fopen("Quote1.txt", "r");
	if(fp == NULL){
		printf("Couldn't load the file!");
		exit(1);
	}

	while(fgets(str, 99, fp) != NULL){
		printf("%s", str);
	}
	fclose(fp);

	return 0;
}

