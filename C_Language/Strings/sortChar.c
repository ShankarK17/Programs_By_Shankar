#include <stdio.h>
#include <string.h>
void swap(char *, char *);
int main(){
	char str[26];
	printf("Enter a string: ");
	scanf("%s", str);
	int i = 1;
	for(char *sp = str; *sp != '\0'; sp++){
		for(char *sp2 = str+i; *sp2 != '\0'; sp2++){
			if(*sp > *sp2){
				swap(sp, sp2);
			}
		}
		i++;
	}

	printf("%s\n", str);
	return 0;
}
void swap(char *a, char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}




