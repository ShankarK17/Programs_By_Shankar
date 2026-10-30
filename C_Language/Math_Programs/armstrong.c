//PROGRAM TO FIND OUT WHETHER A NUMBER IS ARMSTRONG OR NOT
#include <stdio.h>
int main(){
	int num, count = 0, mul = 1, result = 0;
	printf("Enter a number: ");
	scanf("%d", &num);

	int temp = num;
	while(temp != 0){
		temp /= 10;
		count++;
	}

	temp = num;
	while(temp > 0){
		int rem = temp % 10;
		for(int i = 1; i<= count; i++)
			mul = mul * rem;
		result += mul;
		mul = 1;
		temp /= 10;
	}

	if(result == num)
		printf("The number %d num is armstrong number.\n", num);
	else
		printf("The number %d is not an armstrong number.\n", num);

	return 0;

}


