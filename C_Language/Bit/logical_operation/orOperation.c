#include <stdio.h>
#include "bitfun.h"

// OR OPERATION CAN BE USED TO SET A BIT i.e MAKING IT 1.

int main(){
	int num, bit;
	printf("Enter a number: ");
	scanf("%d", &num);

	showbits(num);

	printf("Enter the bit you want to SET: ");
	scanf("%d", &bit);

	int new = setbit(num, bit);
	printf("The new value is: %d \n", new);

	return 0;
}	
