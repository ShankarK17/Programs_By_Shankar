#include <stdio.h>

int main(){
	int a[5] = {81, 72, 36, 94, 51};
	void *vp;
	vp = a;

	printf("value of element 1: %d\n", *(int *)vp ); // HAVE TO TYPECAST VOID POINTER BEFORE USING IT.
	for(int i = 1; i < 5; i++){
		(int *) vp = (int *)vp +1;
		printf("value of element %d: %d\n", i+1, *(int *)vp );
	}

	return 0;
}	
