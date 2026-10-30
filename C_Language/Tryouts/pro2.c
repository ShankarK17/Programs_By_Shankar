#include <stdio.h>
#include "static.h"
extern int func();
int main(){
	extern int x;
	printf("%d\n", x);
	func();
	x = 7;
	printf("%d \n", x);

	return 0;
}

