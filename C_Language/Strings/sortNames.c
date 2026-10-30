#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char *names[5], str[20];
	char *ptr, *temp;
	int i, j, len;
	for(i = 0; i<5; i++){
		printf("Enter a name: ");
		scanf("%s", str);
		len = strlen(str);
		ptr = (char *)malloc(len+1);
		strcpy(ptr, str);
		names[i] = ptr;
	}

	for(i = 0; i<5; i++){
		for(j = i+1; j<5; j++){
			if((strcmp(i[names], j[names])) > 0){
				temp = i[names];
				i[names] = j[names];
				j[names] = temp;
			}
		}
	}	
	
 	printf("After sorting the names:-\n");
	for(int i = 0; i<5; i++)
		printf("%s\n", names[i]);

	return 0;
}


