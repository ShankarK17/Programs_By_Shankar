#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *strremstr(char *, char *);	
int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Invalid number of argument passed!");
		exit(1);
	}
	
	char *res;
	res = (char *)calloc(strlen(argv[1] + 1), sizeof(char));

	char *start = res;
	if(res == NULL){
		printf("No memory!");
		exit(1);
	}
	char *temp = strstr(argv[1], argv[2]);
	/*
	if(temp == NULL){
		printf("Duplicate string not found!\n");
		return 0;
	}
	*/
	char *p = argv[1];
	int len = strlen(argv[2]);
	temp = temp + len;

	while(p < temp){
		*res = *p;
		res++;
		p++;
	}
	char *help = strremstr(temp, argv[2]);
	while(*help != '\0'){
		*res = *help;
		res++;
		help++;
	}
	*res = '\0';
	if(res == NULL){
		printf("Duplicate string not found in main string\n");
	}else{
		printf("%s\n", start);
	}
	free(start);

	return 0;
}



char *strremstr(char *str1, char *str2){
	static char out[100];
	
	char *p = str1;
	char *check;

	int len = strlen(str2);
	int i = 0;
	while(*p != '\0'){
		check = strstr(p, str2);
		if(check == NULL){
			while(*p != '\0'){
				out[i] = *p;
				i++;
				p++;
			}
			break;
		}
		else{
			while(p < check){
				out[i] = *p;
				i++;
				p++;
			}
			p = p + len;
		}
	}

	
	out[i] = '\0';	
	return out;
}

