// PROGRAM TO CHECK WHETHER A CREDIT CARD NUMBER IS VALID OR NOT BASED ON SAME PRE-DEFINED RULES
#include <stdio.h>
#include <string.h>
int main(){
	char cardno[16];
	int num[16] = {0};
	int *ip = num;
	printf("Enter a 16-digits credit card number: ");
	scanf("%s", cardno);

	char *sp = cardno;
	while(*sp != '\0'){
		*ip = (int)(*sp - 48);
		ip++;
		sp++;
	}
	int sum1 = 0, sum2 = 0;
	int i = 15;
	while(i >= 0){
		if(i % 2 == 0){
			num[i] *= 2;
			if(num[i] >= 10)
				num[i] -= 9;
			sum1 += num[i];

		}else
			sum2 += num[i];

		i--;
	}
	
	/*
	for(int i = 0; i<16; i++)
		printf("%d ", num[i]);

	printf("\n");
	*/

	if((sum1+sum2) % 10 == 0)
		printf("The given credit card is valid\n");
	else
		printf("The given credit card is not valid!\n");


	return 0;
}



