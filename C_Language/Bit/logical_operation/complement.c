#include <stdio.h>
int main(){
	unsigned char ch = 32, dh;
	dh = ~ch;
	printf("ch = %c ", ch);

	printf("~ch = %d ", dh);
	printf("~ch = %c ", dh);
	printf("~ch = %x ", dh);
	printf("~ch = %#X ", dh);

	return 0;
}
