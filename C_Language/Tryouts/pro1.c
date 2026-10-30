#include <stdio.h>
#include "static.h"

int func(){
	//extern int x;
	printf("%d\n", x);
	x = 6;
	printf("%d \n", x);

	return 0;
}
