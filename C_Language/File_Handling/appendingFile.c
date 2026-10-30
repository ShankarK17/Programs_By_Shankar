#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE *fp;
	char c;
	fp = fopen("appended.txt", "a");
	if(fp == NULL){
		printf("Couldn't load!");
		exit(1);
	}
	char arr[100];
	printf("Enter text to append: ");
	scanf("%s", arr);
	int i, len = strlen(arr);
	for(i = 0; i<len; i++){
		c = arr[i];
		fputc(c, fp);
	}
	fclose(fp);

	return 0;
}

