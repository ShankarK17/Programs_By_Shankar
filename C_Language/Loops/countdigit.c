#include <stdio.h>
int main(){
	//PROGRAM TO COUNT TO NUMBER OF DIGITS IN A NUMBER ENTERED
	int n, count = 0;
	printf("Enter a number: ");
	scanf("%d", &n);
	int temp = n;

	while(temp != 0){
		temp /= 10;
		count++;
	}

	printf("The numbers of digits in number %d is %d digits\n", n, count);

	return 0;
}

