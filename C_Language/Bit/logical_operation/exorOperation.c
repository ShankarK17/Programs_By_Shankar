#include <stdio.h>
#include "bitfun.h"

//PROGRAM TO TOGGLE A BIT i.e if the bit is 1 make it 0 and if it's 0 make it 1.
//CAN BE IMPLEMENTED USING XOR OPERATION (^)

int main(){
	int num, bit;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	showbits(num);

	printf("Enter the bit you want to toggle: ");
	scanf("%d", &bit);

	int new = togglebit(num, bit);
	printf("The new value after toggling the %d bit is %d\n", bit, new);

	return 0;
}
