#include <stdio.h>
#include "customfun.h"

int main()
{
	int a = 5;
	int b = 10;
	int sum, diff, product, divide, mod;

	sum = funAdd(a,b);
	diff = funSub(a,b);
	product = funMul(a,b);
	divide = funDiv(a,b);
	mod = funMod(a,b);

	printf("sum = %d\n",sum);
	printf("Difference = %d\n",diff);
	printf("Product = %d\n", product);
	printf("Quotient = %d\n", divide);
	printf("Remainder = %d\n", mod);

	return 0;
}
