#include <stdio.h>
#include "strfun.h"

int main(){
	char str[50];
	printf("Enter a string: ");
	scanf("%[^\n]s", str);

	char sub[50];
	printf("Enter the string to be searched: ");
	scanf(" %[^\n]s", sub);

	char *res = strxstr(str, sub);
	printf("%s\n", res);

	printf("Enter a string: ");
	scanf(" %[^\n]s", str);
	char ch;

	printf("Enter a character to remove: ");
	scanf(" %c", &ch);

	char *updatedstr = strremc(str, ch);
	printf("%s\n", updatedstr);
	
	char s[100];
	printf("Enter a string: ");
	scanf(" %[^\n]s", s);

	char remsub[100];
	printf("Enter a substring to remove: ");
	scanf(" %[^\n]s", remsub);
	char *output = strremstr(s, remsub);

	printf("%s\n", output);

	return 0;
}
