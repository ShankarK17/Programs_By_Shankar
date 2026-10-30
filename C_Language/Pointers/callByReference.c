#include <stdio.h>
void swap(int *, int *, char *);
int main(){
	int a = 5, b = 6;
	char c = 's';
	printf("Before using the function swap a = %d & b = %d\n", a, b);

	swap(&a, &b, &c);

	printf("After swapping the values a = %d & b = %d\n", a, b);
	printf("%c\n", c);
	return 0;
}

void swap(int *x, int *y, char *cp){
	int temp = *x;
	*x = *y = temp;
	*cp = (*x == *y)? 'y':'n';

	return ;
}



