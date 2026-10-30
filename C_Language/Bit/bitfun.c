#include <stdio.h>
#include "bitfun.h"

void showbits(unsigned int n){
	unsigned int k, j, mask;

	for(int i = 7; i >= 0; i--){
		j = i;
		mask = 1 << j;
		k = n & mask;
		k == 0? printf("0"): printf("1");
	}
	printf("\n");
}

void checkbits(unsigned int n, unsigned int i){
	unsigned int j, mask;
	mask = 1 << i;

	j = n & mask;
	if(j == 0)
		printf("The %d bit is OFF\n", i);
	else
		printf("The %d bit is ON\n", i);
	
	showbits(n);
}

int offbit(unsigned int n, unsigned int i){
	unsigned int j, mask;

	mask = ~(1 << i);

	j = n & mask;
	if(j == 0)
		printf("The %d bit is already OFF\n", i);
	else
		printf("Now the %d bit is OFF\n", i);

	n = n & mask;
	showbits(n);

	return n;
}

int setbit(unsigned int n, unsigned int i){
	unsigned int mask;

	mask = 1 << i;
	
	n = n | mask;

	showbits(n);

	return n;
}

int togglebit(unsigned int n, unsigned int i){
	unsigned int mask;

	mask = 1 << i;

	n = n ^ mask;
	showbits(n);

	return n;
}





	
