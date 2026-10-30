#include <stdio.h>

int main(){
	int a = 5, b = 10, *pa, *pb, *pc;
	pa = &a;
	pb = &b;
	pc = &a;
	int *pn = NULL;
	void *pv = &b; //CAN STORE ADDRESS OF ANY VARIABLE 

	if(pa == pc){
		printf("The address in pointer A and pointer C are same. ");
		printf("i.e pa = %u & pc = %u \n", pa, pc);
	}

	if(pb != pc){
		printf("The address in pointer B & pointer C are not some. ");
		printf("i.e pb = %u & pc = %u \n", pb, pc);
	}

	printf("Address in the NULL pointer is %u \n", pn);
	printf("Address in Void pointer is %u \n", pv);

	return 0;
}
	

