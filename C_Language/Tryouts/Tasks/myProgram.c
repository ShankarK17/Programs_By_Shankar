#include <stdio.h>
static int sqr(int);
extern int cube(int);

int main(){
	int a = 5;
	// this is valid as function cube is extern/global by default
	printf("The cube of a = %d\n", cube(a));
	// This below line will cause an error as function declared static cannot be used defined in other file
	//printf("The square of a = %d\n", square(a));
	

	return 0;
}


