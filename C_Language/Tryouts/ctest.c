#include <stdio.h>
int main(){
	/*TO CHECK ADDRESS OF DIFFERENT TYPE OF POINTERS
	 * char *ptr;
	int *ptr1;
	float *ptr2;

	printf("%d %d %d", sizeof(ptr), sizeof(ptr1), sizeof(ptr2));
	*/

	extern int i;
	printf("%ld\n", sizeof(i));
	return 0;
}
int i = 20;
