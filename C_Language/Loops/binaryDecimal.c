//PROGRAM TO CONVERT ANY BINARY VALUE TO IT'S CORRESPONDING DECIMAL VALUE
#include <stdio.h>

int main(){
	int bi, place = 1, dec = 0;
	printf("Enter a binary number(0s & 1s): ");
	scanf("%d", &bi);
	int temp = bi;

	while(bi > 0){
		int rem = bi % 10;
		dec = dec + rem * place;
		place *= 2;
		bi /=10;
	}

	printf("The value of %d is %d\n", temp, dec);

	return 0;
}
