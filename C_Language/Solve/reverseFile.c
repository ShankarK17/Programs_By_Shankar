#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fs, *ft;
	fs = fopen("file.txt", "r");
	if(fs == NULL){
		printf("Error while opening the file!");
		exit(1);
	}

	ft = fopen("reversedfile.txt", "w");
	if(ft == NULL){
		printf("Error while opening reversed file!");
		exit(1);
	}

	char ch;
	fseek(fs, 0, SEEK_END);
	fseek(ft, 0, SEEK_SET);
	long size = ftell(fs);
       	int i;	
	for(i = size; i >= 0; i--){
		fseek(fs, i, 0);
		ch = fgetc(fs);
		fputc(ch, ft);
	}
	fclose(fs);
	fclose(ft);

	return 0;
}


