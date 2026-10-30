#include <stdio.h>

void display();

int main(){
	printf("this is the address of main function: %u\n", main);
	display();
	printf("this is the address of display function: %u\n", display);

	return 0;
}

void display(){
	printf("this is the diplay function.\n");
}

