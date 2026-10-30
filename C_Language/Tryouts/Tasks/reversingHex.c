#include <stdio.h>
#include <math.h>
int reversehex(int);
int main(){
	int num;
	printf("Enter a hex value: ");
	scanf("%x", &num);

	int newhex = reversehex(num);
	printf("The reverse hex is %X\n", newhex);

	return 0;
}

int reversehex(int num){
	int temp = num, power = 0, revhex = 0;
	while(temp > 0){
		temp /= 16;
		power++;
	}

	while(power > 0){
		int rem = num % 16;
		revhex = revhex + rem * pow(16, power-1);
		num /= 16;
		power--;
	}

	return revhex;

}

