#include <stdio.h>
int main(){
	int num, i;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	for(i = 2; i*i <= num; i++){
		if(num % i == 0){
			break;
		}
	}
	if(i*i > num)
		printf("The number %d is prime\n",num);
	else
		printf("The number %d is not prime\n",num);

	
	return 0;
}
	
