//PROGRAM TO DEMONSTRATE FUNCTION POINTERS, i.e ACCESSING FUNCTION VIA POINTER TO FUNCTION MEANS STORING ADDRESS OF FUNCTIONS
#include <stdio.h>
#define PI 3.14
float area(int, void (*)(float));
void display(float);
int main(){
	float (*fptr)(int, void(*)(float)), result;
	fptr = area;
	void (*dptr)(float) = display;

	int rad;
	printf("Enter the radius of circle: ");
	scanf("%d", &rad);

	(*fptr)(rad, dptr);

	return 0;
}

float area(int r, void(*dp)(float)){
	float res = PI * (float) r * r ;
	(*dp)(res);
}

void display(float a){
	printf("area of cirle: %f\n", a);
}

