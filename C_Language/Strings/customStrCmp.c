#include <stdio.h>

int customcmp(char *, char *);

int main(){
	char str1[50], str2[50];
	printf("Enter String 1: ");
	scanf("%[^\n]s", str1);

	printf("Enter String 2: ");
	scanf(" %[^\n]s", str2);

	int res = customcmp(str1, str2);
	
	if(res == 1)
		printf("The two strings are not equals.\n");
	else
		printf("The two strings are similar.\n");

	return 0;

}

int customcmp(char *s1, char *s2){
	int same = 1;

	while(*s1 != '\0'){
		if(*s1 == *s2){
			s1++;
			s2++;
		}
		else{
			printf("the diff is %d \n", *s1 - *s2);
			break;
		}
	}

	if(*s1 == '\0')
		same = 0;

	return same;
}

