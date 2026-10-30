#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fp;
	fp = fopen("somefile.txt", "r");
	if(fp == NULL){
		printf("Couldn't load!");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	//printf("%ld\n", size);
	//printf("File position: %ld\n", ftell(fp));
	int i, ch;

	for(i = 1; i<= size; i++){
		fseek(fp, -i, SEEK_END);
		ch = fgetc(fp);
		printf("%c", ch);
	}
	printf("\n");
	fclose(fp);
	return 0;
}


