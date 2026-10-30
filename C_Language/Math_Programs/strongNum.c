//PROGRAM TO FIND OUT THE STRONG NUMBER
#include <stdio.h>

int main(){
	int num, result = 0, fact = 1;
	printf("Enter a number: ");
	scanf("%d", &num);

	int temp = num;
	while(temp != 0){
		int rem = temp % 10;
		for(int i = 1; i<= rem; i++)
			fact = fact * i;
		result += fact;
		fact = 1;
		temp /= 10;
	}

	if(result == num)
		printf("The number %d is a strong number\n", num);
	else
		printf("The number %d is not a strong number\n", num);

	return 0;
}


