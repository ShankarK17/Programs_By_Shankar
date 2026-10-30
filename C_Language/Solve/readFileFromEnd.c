#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	char ch;
	fp = fopen("file.txt", "r");
	if(fp == NULL){
		printf("Error while opening the file");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	long loc = ftell(fp);
	for(int i = 1; i <= loc; i++){
		fseek(fp, -i, SEEK_END);
		ch = fgetc(fp);
		printf("%c", ch);
	}
	fclose(fp);

	return 0;
}
