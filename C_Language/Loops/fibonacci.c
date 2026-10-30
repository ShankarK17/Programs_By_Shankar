#include <stdio.h>
int main(){
	int nth, result;
	printf("Enter the term you want to find out: ");
	scanf("%d", &nth);

	int a = 0, b = 1;

	for(int i = 1; i<= nth; i++){
		printf("%d ", a);
		result = a + b;
		a = b;
		b = result;
	}
	printf("\n");

	return 0;
}
