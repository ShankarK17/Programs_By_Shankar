#include <stdio.h>
#define _BV(x) (1 << x)
int main(){
	unsigned char num,j;
	printf("Enter a number: ");
	scanf("%hhd", &num);

	for(int i = 7; i >= 0; i--){
		j = num & _BV(i);
		j == 0? printf("0"): printf("1");
	}
	printf("\n");

	return 0;
}


