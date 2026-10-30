#include <stdio.h>
#include <string.h>

int main(){
	char strs[5][50];

	printf("Enter 5 strings: ");
	for(int i = 0; i<5; i++)
		scanf("%s",strs[i]);
	printf("\n");

	for(int j=0; j<5; j++){
		printf("%s",strs[j]);
		printf("\n");
	}

	printf("\n");

	return 0;
}

