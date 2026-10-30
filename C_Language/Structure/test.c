#include <stdio.h>
struct book{
	char name[50];
	int price;
};
void fun(struct book b){
	printf("Callin fun");
}

void fun1(struct book *bp){
	printf("Calling fun1");
}


int main(){

	struct book b1 = {"letusc", 400};
	struct book *sp = &b1;

	fun(b1);

	fun1(&b1);

	return 0;
}




