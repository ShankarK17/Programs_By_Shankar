#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *locate(char *,char *);
int main(){
	char str[101];
	printf("Enter a String: ");
	scanf("%[^\n]s", str);
	
	scanf("%*c");
	char sub[100];
	printf("Enter a Substring to find: ");
	scanf("%s", sub);

	char *output = locate(str, sub);

	if(output == NULL){
		printf("No match found\n");
	}
	else
	{

		printf("%s\n", output);
	}
	
	return 0;
}

char *locate(char *s, char *t){
	if(*t == '\0'){
		return s;
	}
	char *p1, *p2, *help;
	for(p1 = s; *p1 != '\0'; p1++){
		help = p1;
		for(p2 = t; *p2 != '\0'; p2++,help++){
			if(*help != *p2){
				break;
			}
		}
		if(*p2 == '\0')
			return p1;
	}
	return NULL;
}



	

