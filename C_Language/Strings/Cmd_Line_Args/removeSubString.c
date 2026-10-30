#include <stdio.h>
#include "strfun.h"
#include <stdlib.h>

int main(int argc, char *argv[]){

	if(argc != 3){
		printf("Only 2 extra arguments expected!\n");
		exit(1);
	}

	char *res = strremstr(argv[1], argv[2]);

	printf("After removing the text \"%s\": %s\n", argv[2], res);

	return 0;
}


