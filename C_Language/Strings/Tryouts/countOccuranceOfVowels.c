#include <stdio.h>
#include <string.h>
int main(){
	char s[100];
	printf("Enter a string: ");
	scanf("%[^\n]s", s);

	int len = strlen(s);
	int count = 0;
	
	char *p = s;
	for(int i = 0; i<len; i++){
		if((p[i] == 'u' || p[i] == 'o' || p[i] == 'i' || p[i] == 'e' || p[i] == 'a') &&
		  ((p[i+1] == 'a' || p[i+1] == 'e' || p[i+1] == 'i' || p[i+1] == 'o' || p[i+1] == 'u'))){
			if(p[i+1] - p[i] < 0)
				count++;
		}
	}

	printf("%s\n", s);
	printf("The count of subsequence vowels is %d\n", count);

	return 0;
}


