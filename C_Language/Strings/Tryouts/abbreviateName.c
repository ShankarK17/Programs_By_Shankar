#include <stdio.h>
#include <string.h>

int main(){
	char names[5][50];
	int i;
	for(i = 0; i<5; i++){
		printf("Enter fullname %d: ", i+1);
		scanf(" %[^\n]", names[i]);
	}

	char abb[5][3], *ptr;
	for(i = 0; i<5; i++){
		ptr = names[i];
		abb[i][0] = *ptr;
		while(*ptr != ' '){
			ptr++;
		}
		abb[i][1] = *(ptr+1);
		abb[i][2] = '\0';
	}
	


	for(int j = 0; j < 5; j++)
		printf("%s ", abb[j]);

	printf("\n");

		


	return 0;
}
