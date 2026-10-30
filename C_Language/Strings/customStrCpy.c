#include <stdio.h>
#include <string.h>
void customcpy(char *, char *);

int main(){
	char *str1 = "Silicon";
	char *str2;

	printf("Enter a string of length > 50: ");
	scanf("%[^\n]s", str1);

	if(strlen(str1) > 50){
		printf("Size of input string too big!\n");
		return 1;
	}
	
	customcpy(str1, str2);

	printf("Original String: %s\tCopied String: %s\n", str1, str2);

	return 0;
}

void customcpy(char *og, char *cp){
	while(*og != '\0'){
		*cp = *og;
		og++;
		cp++;
	}

	*cp = '\0';
}



