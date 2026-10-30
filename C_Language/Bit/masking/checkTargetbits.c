#include <stdio.h>
#include "bitfun.h"
#define _BV(x) (1 << x)
void targetbits(unsigned int, int, int);

int main(){
	unsigned int n;
	int position, noOfbits;
	printf("Enter the even number: ");
	scanf("%d", &n);

	showbits(n);

	printf("Enter the position from where to check: ");
	scanf("%d", &position);

	printf("Enter the no of Bits to check from the %d position: ", position);
	scanf("%d", &noOfbits);

	targetbits(n, position, noOfbits);

	return 0;
}

void targetbits(unsigned int num, int pos, int no){
	unsigned int j;
	int count = 0;

	for(int i = pos; i > 0; i--){
		j = num & _BV(i);
	       if(j != 0)
		       count++;
	}

	if(count == no)
		printf("True\n");
	else
		printf("False\n");

}
	       	       







