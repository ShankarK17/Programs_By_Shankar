#include <stdio.h>
#include "strfun.h"
#include <string.h>
char *strxstr(char *str1, char *str2){
	char *p1, *p2, *help;

	if(*str2 == '\0')
		return str1;

	for(p1 = str1; *p1 != '\0'; p1++){
		help = p1;
		for(p2 = str2; *p2 != '\0'; p2++, help++){
			if(*help != *p2)
				break;
		}
		if(*p2 == '\0')
			return p1;
	}

	return NULL;
}

char *strremc(char str[], int ch){
	if(str[0] == '\0')
		return NULL;
	int i = 0, j = 0;
	while(str[i] != '\0'){
		if(str[i] != ch){
			str[j] = str[i];
			j++;
		}
		i++;
	}

	str[j] = '\0';
	return str;

}

char *strremstr(char *str1, char *str2){
	int len = strlen(str2);
	if(len == 0)
		return str1;

	static char res[100];
	char *temp = strxstr(str1, str2);
	int i = 0;
	if(temp == NULL)
		return 0;
	while((str1+i) < temp){
		res[i] = str1[i];
		i++;
	}
	char *p = temp + len;
	while(*p != '\0'){
		res[i++] = *p++;
	}
	res[i] = '\0';	

	return res;
}

