#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("somefile.txt", "a");
	if(fp == NULL){
		printf("Error while opening the file!");
		exit(1);
	}
	char str[100];
	while(1){
	printf("Enter a text: ");
	fgets(str, 100, stdin);
		if(str[0] == '\n')
			break;
		fputs(str, fp);
	}

	fclose(fp);

	return 0;
}

	
	
