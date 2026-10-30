#include <stdio.h>
//PI is called the macro template & value after it is called macro expansion,
// done by the preprocessor before compiler works, it replaces the values
#define PI 3.1428

int main()
{
	float rad = 5.25f, area;
	area = PI * rad * rad;
	printf("Area of the circle with radius %.2f is %.4f\n", rad, area);
	
	return 0;
}
	
