#include <stdio.h>
#define _BV(x) (1 << x)

// On means 1 and Off means 0
void showBits(unsigned int);

int main(){
	unsigned int num, j;
	int bit;
	printf("Enter a number: ");
	scanf("%d", &num);

	printf("Enter the bit to check: ");
	scanf("%d", &bit);

	j = num & _BV(bit);
	if(j == 0)
		printf("The %d bit is OFF/CLEAR\n", bit);
	else
		printf("The %d bit is ON/SET\n", bit);

	showBits(num);

	printf("Enter the bit you want to clear:  ");
	scanf("%d", &bit);

	j = num & _BV(bit);
	if (j == 0)
		printf("The %d bit is already OFF\n", bit);
	else
		num = num & ~(_BV(bit));
	printf("After turning OFF the %d bit new value is \n", bit);
	showBits(num);

	return 0;
}
