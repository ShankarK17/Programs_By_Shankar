#include <stdio.h>
#include <string.h>
int main(){
	char name[20];
	printf("Enter your full name: ");
	gets(name);
	printf("Your full name is ");
	puts(name);

	return 0;
}

