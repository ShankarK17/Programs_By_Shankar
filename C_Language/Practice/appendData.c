#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Invalid number of arguments");
		exit(1);
	}

	FILE *fs, *ft;
	fs = fopen(argv[1], "r");
	if(fs == NULL){
		printf("Couldn't load file!");
		exit(1);
	}
	char ch;
	while(1){
		ch = getc(fs);
		if(ch == EOF)
			break;
		printf("%c",ch);
	}
	
	fclose(fs);

	ft = fopen(argv[2], "r");
	if(ft == NULL){
		printf("Couldn't open file!");
		exit(1);
	}
	fs = fopen(argv[1], "a");
	if(fs == NULL){
		printf("Error while opening the file");
		exit(1);
	}

	while(1){
		ch = getc(ft);
		if(ch == EOF)
			break;
		printf("%c", ch);
		fputc(ch, fs);
	}
	fclose(fs);
	fclose(ft);	

	return 0;
}
		






