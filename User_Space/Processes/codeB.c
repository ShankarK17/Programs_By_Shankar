#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Invalid inputs!\n");
		return 1;
	}
	int res = atoi(argv[1]);
	printf("Square: %d\n", res*res);
	return 0;
}

