#include <stdio.h>
#include <string.h>
int main(){
	char sent[80];
	printf("Enter a string no longer than 80 characters: ");
	scanf("%[^\n]s", sent);

	if(strlen(sent) > 80){
		printf("Text greater than valid limit!");
		return 0;
	}
	char *ptr = sent, *str;
	str = sent;
	while(*ptr != '\0'){
		if(*ptr != 'a' || *ptr != 'e' || *ptr != 'i' || *ptr != 'o' || *ptr != 'u' || 
		   *ptr != 'A' || *ptr != 'E' || *ptr != 'I' || *ptr != 'O' || *ptr != 'U'){
			*str = *ptr;
			str++;
		}
		ptr++;
	}
	*str = '\0';

	printf(" %s\n", sent);

	return 0;
}
	
