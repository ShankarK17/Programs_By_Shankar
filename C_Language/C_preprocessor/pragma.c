#include <stdio.h>
void func1() __attribute__((constructor));
void func2() __attribute__((destructor));
// PRAGMA DIRECTIVE ALLOWS US TO EXECUTE CERTAIN FUNCTION AT SPECIFIC TIMES LIKE BEFORE MAIN FUNCTION OR END OF PROGRAM

int main(){
	printf("Message from main funcation\n");
	return 0;
}

void func1(){
	printf("Message from function 1\n");
}

void func2(){
	printf("Message from function 2\n");
}

