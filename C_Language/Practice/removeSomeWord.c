#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE *fp, *fo;
	fp = fopen("Sentence.txt", "r");
	if(fp == NULL){
		printf("Couldn't load file");
		exit(1);
	}
	fo = fopen("UpdatedSentence.txt", "w");
	if(fo == NULL){
		printf("no space available!");
		exit(1);
	}
	
	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	char *str = (char *)malloc(size+1);
	if(str == NULL){
		printf("No memory!");
		fclose(fp);
		exit(1);
	}

	rewind(fp);
	//char *temp = " ";
	char *help = str;
	while(fscanf(fp, "%s", str) != EOF){
		if(strcmp(str, "the") == 0 || strcmp(str, "The") == 0 || strcmp(str, "a") == 0 || strcmp(str,"a") == 0){
			fprintf(fo,"%s", "");
		}else{
			fprintf(fo,"%s ", str);
		}
	}

	fclose(fp);
	fclose(fo);
	free(help);

	return 0;
}
