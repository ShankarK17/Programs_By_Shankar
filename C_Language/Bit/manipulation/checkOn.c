#include <stdio.h>
#include "bitfun.h"

int main(){
	unsigned char num;
	printf("Enter a number: ");
	scanf("%hhd", &num);

	showbits(num);

	unsigned char a,b;
	a = num & (1 << 3);
	b = num & (1 << 5);

	if(a == 0){
		printf("The 3rd bit was OFF\n");
		num |= (1 << 3);
		showbits(num);
	}
	else
		printf("The 3rd bit is already ON\n");

	if(b == 0){
		printf("The 5th bit was OFF\n");
		num |= (1 << 5);
		showbits(num);
	}
	else
		printf("The 5th bit is already ON\n");
	
	return 0;

}
