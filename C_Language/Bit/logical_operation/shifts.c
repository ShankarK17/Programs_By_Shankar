#include <stdio.h>
void showBits(unsigned int);
int main(){
	/*int n = 5;
	int x = 2;
	printf("The value of %d after right shift by %d is %d ", n, x, n >> x);
	printf("The value of %d after left shift by %d is %d\n", n, x, n << x);
	*/

	int num = -6, temp;
	printf("%d in binary: ", num);
	showBits(num);

	temp = num >> 1;
	printf("%d >> 1 in binary: ", num);
	showBits(temp);

	temp = num << 2;
	printf("%d << 2 in binary: ", num);
	showBits(temp);

	temp = num >> 4;
	printf("%d >> 4 in binary: ", num);
	showBits(temp);

	return 0;
}
