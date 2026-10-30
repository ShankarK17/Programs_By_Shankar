//PROGRAM TO ADD TWO NUMBER WITHOUT USING THE + OR INCREMENT OPERATOR
#include <stdio.h>
int main(){
	int a,b;
	printf("Enter two number: ");
	scanf("%d %d", &a, &b);

	int sum, carry;

	while(b !=0){
		sum = a ^ b;
		carry = (a & b) << 1;
		a = sum;
		b = carry;
	}

	printf("The sum = %d\n", sum);
	return 0;
}	
