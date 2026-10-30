#include <stdio.h>

int customlen(char *);

int main(){
	char str[50];
	printf("Enter a string: ");
	scanf("%[^\n]s", str);

	int len = customlen(str);

	printf("The Length of the String \"%s\" is %d\n", str, len);
	return 0;

}

int customlen(char *cp){
	int len = 0;
	while(*cp != '\0'){
		len++;
		cp++;
	}

	return len;
}
