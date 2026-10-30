#include <stdio.h>

int main(){
	struct author{
		char name[50];
		int age;
	};
	struct book{
		char title[50];
		int price;
		int pages;
		struct author a;
	};

	struct book b1 = {"LetusC", 430, 512, "Yashwant.k", 56};
	printf("Title: %s\t Price: %d\t", b1.title, b1.price);
	printf("Pages: %d\t Auther: %s\n", b1.pages, b1.a.name);

	return 0;
}
