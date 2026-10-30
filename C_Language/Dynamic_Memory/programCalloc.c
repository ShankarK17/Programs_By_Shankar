#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n, i;
	char *p;
	printf("Enter number of characters to be entered: ");
	scanf("%d", &n);

	p = (char *)calloc(n, sizeof(char));

	for(i = 0; i<n; i++){
		printf("Enter a character: ");
		scanf(" %c", p+i);
	}
	*(p+i) = '\0';
	printf("Len = %d\n", strlen(p));
	printf("%s\n", p);

	return 0;
}
