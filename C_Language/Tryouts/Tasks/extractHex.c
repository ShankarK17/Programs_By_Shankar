#include <stdio.h>
int main(){
	int num;
	printf("Enter a hex value: ");
	scanf("%x", &num);

        unsigned char ch = num;
	printf("The extracted part from hexa is %X\n", ch);
	
	return 0;
}
