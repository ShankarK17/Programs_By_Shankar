#include <stdio.h>
#include <stdlib.h>
	int main(){
		FILE *fp;
		fp = fopen("TestFile.txt", "a");
		if(fp == NULL){
			printf("Error while opening the file");
			exit(1);
		}

		char str[80];
		while(1){
			fgets(str, 80, stdin);
			if(str[0] == '\n')
				break;
			fputs(str, fp);
		}

		fclose(fp);

		return 0;
}
