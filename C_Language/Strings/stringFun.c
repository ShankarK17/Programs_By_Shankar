#include <stdio.h>
#include <string.h>

int main(){
	char company[] = "Silicon Signals", copy[20];
	printf("String1 = %s\tlenght of string = %ld\n", company, strlen(company));

	strcpy(copy, company);
	printf("String2 = %s\tlenght of string = %ld\n", copy, strlen(copy));

	char str[] = "Silicon";
	int isSame = strcmp(company, str);
	if(isSame)
		printf("The two strings are not same.\n");
	else
		printf("The two strings are same.\n");

	strcat(company, " LLP");
	printf("Updated string = %s\n", company);
	return 0;
}
