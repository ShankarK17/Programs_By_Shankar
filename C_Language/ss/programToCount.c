#include <stdio.h>
int main(){
	FILE *fp;
	char ch;
	int noOfLines = 0, noOfSpaces = 0, noOfChar = 0;

	fp = fopen("File.txt", "r");
	while(1){
		ch = fgetc(fp);
		if(ch == EOF)
			break;
		noOfChar++;
		if(ch == ' ')
			noOfSpaces++;
		if(ch == '\n')
			noOfLines++;
	}
	fclose(fp);

	printf("The numbers of character in files are: %d\n", noOfChar);
	printf("The numbers of blank spaces in files are: %d\n", noOfSpaces);
	printf("The numbers of lines in files are: %d\n", noOfLines);

	return 0;
}
