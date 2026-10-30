#include <stdio.h>
void incr();
void decr();
int main(){
	incr();
	incr();
	incr();

	decr();
	decr();
	decr();
	return 0;

}

void incr(){
	static int i = 0;
	i++;
	printf("The value of i is %d\n", i);
}

void decr(){
	int j = 5;
	j--;
	printf("The value of j is %d\n", j);
}



