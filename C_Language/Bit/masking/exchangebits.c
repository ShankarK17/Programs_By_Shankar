#include <stdio.h>

void display16(unsigned int);
int exchange8(unsigned int);

int main(){
	unsigned short num;
	printf("Enter a 16-bit number: ");
	scanf("%hu", &num);

	display16(num);

	unsigned short new = exchange8(num);

	display16(new);

	return 0;
}

void display16(unsigned int n){
	unsigned int j;

	for(int i = 15; i>=0; i--){
		j = n & (1 << i);
		j == 0? printf("0"): printf("1");
	}
	printf("\n");
}

int exchange8(unsigned int n){
	unsigned int short lhalf, rhalf;
	unsigned int temp;
	
	lhalf = n << 8;
	rhalf = n >> 8;

	temp = lhalf | rhalf;

	return temp;
}
