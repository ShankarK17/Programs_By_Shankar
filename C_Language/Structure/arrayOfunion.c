//PROGRAM TO CREATE ARRAY WITH DIFFERNET DATATYPES(DISSIMILAR)
#include <stdio.h>
int main(){
	union diff{
		int i;
		char c;
		float f;
		double d;
	};// Size will be 8 byets as the largest member is of type long
	
	union diff arr[10];

	arr[0].i = 5;
	arr[1].c = 's';
	arr[2].f = 14.7f;
	arr[3].d = 3.145;

	printf("Array first element: %d\n", arr[0].i);
	printf("Array Second element: %c\n", arr[1].c);
	printf("Array third element: %f\n", arr[2].f);
	printf("Array fourth element: %lf\n", arr[3].d);

	return 0;
}
