// PROGRAM TO CHECK IF A NUMBER IS PALINDROME OR NOT
#include <stdio.h>

int main(){
	int num, revnum = 0;
	printf("Enter a number: ");
	scanf("%d", &num);

	int temp = num;

	while(temp != 0){
		int rem = temp % 10;
		revnum = revnum * 10 + rem;
		temp /=10;
	}

	if(revnum == num)
		printf("The number %d is palindrome\n", num);
	else
		printf("The number %d is not palindrome\n", num);

	return 0;
}

