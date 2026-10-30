#include <stdio.h>
#include <stdlib.h>
struct self {
	int a;
	char b;
	struct self *ptr;
};
int main(){


	struct self svar1, svar2;

	svar1.a = 11;
	svar1.b = 'S';
	svar1.ptr = NULL;
	
	svar2.a = 17;	
	svar2.b = 'K';
	svar2.ptr = NULL;

	svar1.ptr = &svar2;
	//Accessing value of svar2 with the help of pointer of svar1
	printf("%d %c\n", svar1.ptr->a, svar1.ptr->b);

	return 0;
}


