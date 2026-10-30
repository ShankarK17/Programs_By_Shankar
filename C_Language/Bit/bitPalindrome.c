#include <stdio.h>
#include "bitfun.h"
#define _BV(x) (1 << x)
int main(){
	int num, i, j, new = 0;
	printf("Enter a number: ");
	scanf("%d", &num);

	showbits(num);
	 i = 7;
	 j = 0;

	 while(i >= 0 && j <=7){
		 int checker = num & _BV(i);
		if(checker){
			new = new | _BV(j);
			j++;
			i--;
		}
		else{
			j++;
			i--;
		}
	}

	printf("On reversing the bits of %d we get: ", num);
	showbits(new);

	if(num == new)
		printf("The Bits are palindrom.\n");
	else
		printf("No the bits are not palindrome.\n");

	
		

	return 0;
}
