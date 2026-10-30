#include <stdio.h>
#include<stdlib.h>
int *fun();
int *fun1();
int main(){
	int *p, *temp1, *temp2, n;
	p = (int *)malloc(sizeof(int));
	if(p == NULL){
		printf("Required memory not available!\n");
		exit(1);
	}
	printf("Before freeing the memory: %u\n", p);
	free(p);
	printf("Before freeing the memory: %u\n", p);
	
	temp1 = fun();
	printf("Value of temp1: %d\n", *temp1);
	temp2 = fun1();
	printf("Value of temp2: %d\n", *temp2);
	return 0;
}

int *fun(){
	int *ptr;
	ptr = (int *)malloc(sizeof(int));
	*ptr = 3;
	free(ptr);
	//ptr = NULL; to avoid undefined behavior i.e dangling pointer
	return ptr;
}

int *fun1(){
	int *ptr2;
	ptr2 = (int *)malloc(sizeof(int));
	*ptr2 = 7;

	return ptr2;
}


