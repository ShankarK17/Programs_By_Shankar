#include <stdio.h>

int main(){
	FILE *fp;//FILE is a structure who's declaration in stdio.h
	char ch;
	fp = fopen("File.txt", "r");
	while(1){
		ch = fgetc(fp);
		if(ch == EOF)
			break;
		printf("%c", ch);
	}

	printf("The program ends here and above is the entire content of file \"File.txt\"\n");
	fclose(fp);

	return 0;
}
