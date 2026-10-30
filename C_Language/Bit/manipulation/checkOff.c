#include <stdio.h>
#include "bitfun.h"

int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);

	showbits(num);

	int x = num & (1 << 3);
	if(x == 0)
		printf("The 3rd bit is OFF\n");
	else{
		printf("The 3rd bit was ON\n");
		num ^= (1 << 3);
	}

	int y = num & (1 << 5);
	if(y == 0)
		printf("The 5th bit is OFF\n");
	else{
		printf("The 5th bit was ON\n");
		num ^= (1 << 5);
	}

	showbits(num);

	return 0;

}
	

	

