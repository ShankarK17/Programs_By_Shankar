#include <stdio.h>
#define MAX(a, b, c) ((a > b)?((a > c)? a: c):((b > c)? b: c))

int main(){
	int x, y, z;
	printf("Enter three values: ");
	scanf("%d %d %d", &x, &y, &z);

	int max = MAX(x, y, z);

	printf("The maximum value of 3 values is %d\n", max);

	return 0;
}
