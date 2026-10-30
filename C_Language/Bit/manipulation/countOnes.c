#include <stdio.h>
#include "bitfun.h"

int main(){

	int num, count = 0;
	printf("Enter a number: ");
	scanf("%d", &num);

	showbits(num);
	int j;

	for(int i= 0; i<= 7; i++){
		j = num & (1 << i);
		if(j != 0)
			count++;
	}

	printf("The numbers of 1s in %d is %d\n", num, count);

	return 0;
}

