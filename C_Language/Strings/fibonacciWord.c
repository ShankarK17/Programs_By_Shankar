#include <stdio.h>
#include <string.h>

int main(){
	char a[50] = "A";
	char b[50] = "B";

	char str[50];
	int n;
	printf("Enter number of terms you want: ");
	scanf("%d", &n);
	do{
		strcpy(str, b);
		strcat(str, a);
		printf("%s\n", str);	
		strcpy(a, b);
		strcpy(b, str);
		n--;
	}
	while(n > 0);

	printf("\n");

	return 0;
}


