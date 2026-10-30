#include <stdio.h>
#include "strfun.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Invalid arguments passed only 2 allowed!");
		exit(1);
	}
	char ch = argv[2][0];
	char *res = strremc(argv[1], ch);

	printf("After removing the char \'%c\' from the string: %s\n", ch, res);

	return 0;
}


