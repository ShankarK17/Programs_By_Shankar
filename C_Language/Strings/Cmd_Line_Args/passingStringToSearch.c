#include <stdio.h>
#include "strfun.h"
#include <stdlib.h>
int main(int argc, char *argv[]){
 	if(argc != 3){
		printf("Pass only 2 strings!");
		exit(1);
	}

	char *res = strxstr(argv[1], argv[2]);

	if(res != NULL)
		printf("Yes text \"%s\" is present in %s\n", argv[2], argv[1]);
	else
		printf("No text \"%s\" is not present in %s\n", argv[2], argv[1]);
		
	return 0;
}
