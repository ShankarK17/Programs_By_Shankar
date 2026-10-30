#include <stdio.h>
#include "strfun.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 4){
		printf("Invalid arguments passed!");
		exit(1);
	}

	char *output = strrepstr(argv[1], argv[2], argv[3]);
	
	printf("After replacing \"%s\" with \"%s\": %s\n", argv[2], argv[3], output);

	return 0;
}

