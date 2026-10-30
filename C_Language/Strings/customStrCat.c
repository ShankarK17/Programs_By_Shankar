#include <stdio.h>
#include <string.h>
void customcat(char *, char *, int);

int main(){
	char str[50];
	char add[50];
	printf("Enter a string: ");
	scanf("%[^\n]s", str);
	
	int len = strlen(str);

	printf("Enter a string you want to append: ");
	scanf(" %[^\n]", add);

	customcat(str, add, len);

	printf("The resultant string is %s\n", str);
	printf("length of str: %ld\n", strlen(str));


	return 0;
}

void customcat(char *s, char *a, int l){
	while(*a != '\0'){
		*(s+l) = *a;
		a++;
		l++;
	}
	*(s+l) = '\0';
}
	

