#include <stdio.h>

int main(){
	struct abc {
		int a;
		char b;
	};

	union xyz {
		int x;
		char y;
	};

	union pqrs{
		char p;
		int q;
		float r;
		double s;
	};

	struct abc var1;
	union xyz var2;
	var2.x = 83;
	union pqrs var3;
	printf("Address of a = %u\n", &var1.a);
	printf("Address of b = %u\n", &var1.b);
	printf("Address of x = %u\n", &var2.x);
	printf("Address of y = %u\n", &var2.y);
	printf("Value of x = %d\t value of y = %c\n", var2.x, var2.y);

	printf("Size of Var3 = %ld\n", sizeof(var3));

	return 0;
}
