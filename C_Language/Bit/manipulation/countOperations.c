#include <stdio.h>
#include "bitfun.h"

int main(){
	int n1, n2, count = 0;
	printf("Enter number 1: ");
	scanf("%d", &n1);

	printf("Enter number 2: ");
	scanf("%d", &n2);

	showbits(n1);
	showbits(n2);

	int i= 0, j, k;

	while(i <= 7){
		j = n1 & (1 << i);
	    	k = n2 & (1 << i);
		if(j != k)
			count++;

		i++;
	}

	printf("To make the Number 1 equal to Number 2 changes in bits required are %d\n", count);

	return 0;
}	




