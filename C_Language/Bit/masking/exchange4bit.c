#include <stdio.h>
#include "bitfun.h"

int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	showbits(num);

	int lhalf = num >> 4;
	int rhalf = num << 4;

	int new = lhalf | rhalf;

	showbits(new);

	return 0;
}
