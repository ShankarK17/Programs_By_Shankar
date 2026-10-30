#include <stdio.h>
int main(){
	int x = 3, *a;
	float y = 1.1f, *b;
	char z = 's', *c;

	a = &x; 
	b = &y;
	c = &z;

	printf("The address of x is %u\n", a);
	printf("The address of y is %u\n", b);
	printf("The address of z is %u\n", c);
	
	printf("The updated address of x is %u\n", ++a);	
	printf("The updated address of y is %u\n", ++b);
	printf("The updated address of z is %u\n", ++c);

	return 0;
}
