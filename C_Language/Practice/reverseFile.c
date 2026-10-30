#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fp;
	fp = fopen("somefile.txt", "r+");
	if(fp == NULL){
		printf("Couldn't load file!");
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp);
	char *res = (char *)malloc(size);
	if(res == NULL){
		printf("No enough memory!");
		fclose(fp);
		exit(1);
	}
	char *output = res;
	rewind(fp);
	int i = 0;
	char ch;
	while(1){
		ch = fgetc(fp);
		if(ch == EOF){
			break;
		}
		res[i] = ch;
		i++;
	}	
	//printf("len : %ld\n", strlen(output));
	//printf("str : %s\n", output);
	
	int start = 0, end = size - 1;
	while(start < end){
		char temp = res[start];
		res[start] = res[end];
		res[end] = temp;
		start++;
		end--;
	}
	rewind(fp);
	//printf("str : %s\n", output);
	while(*res != '\0'){
		fputc(*res, fp);
		res++;
	}
	fclose(fp);
	free(output);



	return 0;
}
