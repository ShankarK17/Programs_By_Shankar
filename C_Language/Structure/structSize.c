#include <stdio.h>
#define pragma pack(1)
struct stcdef3 {
	char p;
	int q;
	char r;
} stc3;

int main(){
	typedef struct stcdef1 {
		char a;
		char b;
		int c;
	} Stc1;

	typedef struct stcdef2 {
		char x;
		int y;
		char z;
	} Stc2;

	Stc1 stc1 = {'a', 'c', 12};
	Stc2 stc2 = {'x', 120, 'z'};

	printf("Size of stc1 = %ld\n", sizeof(stc1));
	printf("Size of stc2 = %ld\n", sizeof(stc2));
	printf("Size of stc3 using pragma = %ld\n", sizeof(stc3));

	return 0;
}
