#include <stdio.h>
#include <string.h>
int main(){
	struct book{
		char name[50];
		int price;
	};
	printf("%ld\n", sizeof(struct book));
	struct book b1 = {"letusc", 430};
	struct book b2, b3;
	strcpy(b2.name, "CinDepth");
	b3 = b1;
	printf("Book 1: Name = %s\t price = %d\n", b1.name, b1.price);
	printf("Book 2: Name = %s\t price = %d\n", b2.name, b2.price);
	printf("Book 3: Name = %s\t price = %d\n", b3.name, b3.price);

	return 0;
}

