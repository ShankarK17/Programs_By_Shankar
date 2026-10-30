#include <stdio.h>
#include <string.h>
int main(){
	char str1[20], str2[20], str3[20], str4[20];

	printf("Enter a phrase with spaces: ");
	scanf("%s%s%s%s", str1, str2, str3, str4);

	printf("%s\tlength = %d\n", str1, strlen(str1));
	printf("%s\tlength = %d\n", str2, strlen(str2));
	printf("%s\tlength = %d\n", str3, strlen(str3));
	printf("%s\tlength = %d\n", str4, strlen(str4));



	return 0;
}
