#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fo, *fc;
	char c;
	fo = fopen("original.txt", "r");
	if(fo == NULL){
		printf("Couldn't load source file!\n");
		exit(1);
	}
	fc = fopen("copy.txt", "w");
	if(fc == NULL){
		printf("Couldn't open target file!\n");
		exit(1);
	}

	while(1){
		c = fgetc(fo);
		if(c == EOF)
			break;
		else
			fputc(c, fc);
	}
	fclose(fo);
	fclose(fc);

	return 0;
}

