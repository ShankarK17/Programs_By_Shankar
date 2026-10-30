#include <stdio.h>

float add(float, int);
float sub(float, int);
float mul(float, int);
float div(float, int);

int main(){
	float (*fptr[4])(float, int) = {add, sub, mul, div};
	int choice, b;
	float result, a;
	do{
	printf("Enter your choice:\n1->Addition\t2->Subtraction\t3->Multiplication\t4->Division\t5->Exit\n");
	printf("Your choice: ");
	scanf("%d", &choice);

	if(choice == 5){
		printf("EXITTED\n");
		return 1;
	}

	if(choice > 5 || choice == 0){
		printf("Invalid option!\n");
		continue;
	}

	printf("Enter two value: ");
	scanf("%f %d", &a, &b);

	printf("The result is %.4f\n", (fptr[choice-1])(a,b));

	}while(choice != 5);

	return 0;
}


float add(float x, int y){
	return x+y;
}
float sub(float x, int y){
	return x-y;
}
float mul(float x, int y){
	return x*y;
}
float div(float x, int y){
	return x/y;
}


