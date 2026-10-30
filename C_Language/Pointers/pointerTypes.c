#include <stdio.h>

int *dang();
int main(){
	int *pn = NULL; // null pointer store address O in memory location means doesn't points to any valid pointer location.
	printf("address of a null pointer: %u\n", pn);

	int *pd = dang(); // dangling pointer, points to location which have been delocated, or freed.
	printf("this is a dangling pointer with address: %u\n", pd);

	char *pc; // wild pointer, it hasn't been initialized i.e will point to some garbage value in memory.
	printf("address of wild pointer: %u\n", pc);

	void *pv = pc; // void pointer can store address of any data_types  we need to explicitly typecast it before using 
	printf("address of void pointer: %u\n", pv);	
}

int *dang(){
	int x = 5, *px = &x;

	return px;
}


