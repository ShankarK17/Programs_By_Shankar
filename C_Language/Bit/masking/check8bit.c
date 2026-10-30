#include <stdio.h>
#include "bitfun.h"

int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	num &= 0xFF;
	showbits(num);

	checkbits(num, 3);
	checkbits(num, 6);
	checkbits(num, 7);

	return 0;
}

	 
