#include <stdio.h>
#include "arearect.h"

int main(){
	int a, b;
	printf("Enter length and breadth of rectangle: ");
	scanf("%d %d", &a, &b);

	printf("Area of Rectangle = %d\n", AREA(a, b));
	printf("Perimeter of rectangle = %d\n", PERI(a, b));

	return 0;
}
