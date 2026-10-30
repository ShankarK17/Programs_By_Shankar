#include <stdio.h>
#include <string.h>
int main(){
	FILE *fp;
	char ch;
	fp = fopen("demo.txt", "w");

	char str[100];
	int i, len;
	printf("Enter text here: ");
	scanf("%[^\n]s", str);
	len = strlen(str);
	for(i = 0; i<len; i++){
		ch = str[i];
		fputc(ch, fp);
	}
	fclose(fp);

	return 0;
}
