#include <stdio.h>
#include <string.h>
int main(){
	char str[50];
	printf("Enter a string: ");
	scanf("%[^\n]s", str);

	if(strlen(str) == 1){
		printf("Enter a valid string!\n");
		return 1;
	}

	int pos, count;
	printf("Enter position & no of character to return: ");
	scanf("%d %d", &pos, &count);

	printf("The extracted part is: ");
	while(count > 0){
		printf("%c", *(str+pos));
		pos++;
		count--;
	}

	printf("\n");

	return 0;

}
