#include <stdio.h>
#include "bitfun.h"

int main(){
	int num, j;
	printf("Enter a number: ");
	scanf("%d", &num);

	showbits(num);

	for(int i = 7; i>= 0; i--){
		if(i == 7 || i == 6 || i == 2 || i == 3){
			j = num & (1 << i);
			if(j == 0){
				num |= (1 << i);
			}
		}else
			num &= ~(1 << i);
	}

	showbits(num);

	return 0;
}
