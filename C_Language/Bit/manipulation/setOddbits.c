#include <stdio.h>
#include "bitfun.h"

int main(){
	int num, j;
	printf("Enter a number: ");
	scanf("%d", &num);

	showbits(num);

	for(int i=1; i<=7; i+=2){
		j = num & (1 << i);
		if(j == 0)
			num ^= (1 << i);
	}
	
	printf("After setting the odd places: " );
	 showbits(num);

	return 0;
}

