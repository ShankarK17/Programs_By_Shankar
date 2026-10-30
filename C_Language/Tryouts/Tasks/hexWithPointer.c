#include <stdio.h>
int main(){
	int num = 0xABCD;
	void *vp = &num;

	printf("The value of num is %X\n", *(int *)vp);
	
       	unsigned char *cp = (unsigned char*)&num;
	*cp >>= 4;

	printf("updated valueof num: %X\n", *cp);

	return 0;
}
