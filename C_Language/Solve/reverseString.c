#include <stdio.h>
#include <string.h>
char *reverse(char *, char *);
int main(){
	char str[100];
	printf("Enter a string: ");
	scanf("%[^\n]s", str);

	char res[100];
	reverse(str, res);

	printf("%s\n", res);

	return 0;
}

char *reverse(char *s, char *t){
	int len = strlen(s) - 1;
	while(len >= 0){
		*t = s[len];
		t++;
		len--;
	}

	return t;
}


