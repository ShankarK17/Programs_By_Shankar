#include <stdio.h>
#include <string.h>
#include <ctype.h>
int mystrcmp(const char *, const char *);
int main(){
	char str1[100];
	printf("Enter string 1: ");
	scanf("%[^\n]s", str1);
	scanf("%*c");
	char str2[100];
	printf("Enter String 2: ");
	scanf("%[^\n]s", str2);
	
	int res = mystrcmp(str1, str2);

	if(res == 0){
		printf("The two strings are equal\n");
	}
	else if(res < 0){
		printf("The string 1 is alphabetically lower\n");
	}
	else
		printf("The string 1 is alphabetically greater\n");

	return 0;
}

int mystrcmp(const char *s1, const char *s2){
	if(*s1 == ' ' && *s2 == ' ' || *s1 == '\n' && *s2 == '\n'){
		return 0;
	}
	else{
		char *p1 = (char *)s1;
		char *p2 = (char *)s2;
		int res;
		while(*p1 != '\0'){
			if(tolower(*p1) != tolower(*p2))
				break;
			p1++;
			p2++;
		}

		res = *p1 - *p2;
		return res;
	}
}
	

