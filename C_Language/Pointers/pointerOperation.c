#include <stdio.h>
int main(){
	int x = 5, *ip = &x;
	char y = 'a', *cp = &y;
	float z = 1.1f, *fp = &z;

	printf("The address of x and value of iptr = %u\n", ip);
	printf("The address of y and value of cptr = %u\n", cp);
	printf("The address of z and value of fptr = %u\n", fp);
	ip++;
	cp -= 3;
	fp += 4;

	printf("Size of int = %d\n", sizeof(x));
	printf("Size of char = %d\n", sizeof(y));
	printf("Size of floar = %d\n", sizeof(z));

	printf("value of iptr after ++ = %u\n", ip);
	printf("value of cptr after -=3 = %u\n", cp);
	printf("value of fptr after +=4 = %u\n", fp);

	return 0;
}

