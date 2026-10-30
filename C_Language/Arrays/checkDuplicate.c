#include <stdio.h>
int main(){
	int num, digits[10] = {0}; 
	printf("Enter a number: ");
	scanf("%d", &num);

	if(num <= 0){
		printf("Invalid number, number must be greater than zero.\n");
		return 1;
	}

	while(num > 0){
		int rem = num % 10;
		if(digits[rem] == 1)
			break; 
		digits[rem] = 1;
		num /= 10;		
	}

	if(num > 0)
		printf("Yes! the number contains duplicate digits.\n");
	else
		printf("No, all the digits of number are unique.\n");
	
	return 0;
}

