#include <stdio.h>
void displaybits(int);
int main(){
	int num = 0xABCD;
	char unsigned ch = num;
	printf("The hexa value = %X\t", num);
	displaybits(num);
	printf("The hexa value in char = %X\t", ch);
	displaybits(ch);
	unsigned char c = num >> 8;
	printf("The hexa value of char c = %X\t", c);
	displaybits(c);	
	return 0;
}

void displaybits(int n){
	int j, i;
	for(i = 15; i >= 0; i--){
		j = n & (1 << i);
		(j == 0)? printf("0"): printf("1");
	}
	printf("\n");

}




