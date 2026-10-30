#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
	FILE *fp;
	fp = fopen("test.txt", "r+");
	if(fp == NULL){
		printf("Couldn't load file!");
		exit(1);
	}
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	int count = 0, i = 1;
	char ch;
	while(1){
		fseek(fp, -i, SEEK_END);
		ch = fgetc(fp);
		if(ch == '\n')
			count++;
		else
			break;
		i++;
	}

	rewind(fp);
	int pos = count - 1;
	fseek(fp, -pos, SEEK_END);
	fputs(argv[1], fp);
	fputc('\n', fp);

	fclose(fp);

	return 0;
}




