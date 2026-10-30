#include <stdio.h>
#include <string.h>

int main(){
	int num;
	printf("Enter a value with not more than 8 digits: ");
	scanf("%d", &num);

	int pv = 10;

	char *digits[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
       	char *teen[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	char *tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};

	if(num < 0){
		printf("Invlaid number!\n");
		return 0;
	}
	if(num == 0){
		printf("Zero\n");
		return 0;
	}
	else{
		if(num >= 10000000){
			printf("%s Crores ", digits[num/10000000]);
			num%=10000000;
		}
		if(num >= 1000000){
			printf("%s ", tens[num/1000000]);
			num%= 1000000;
		}

		if(num >= 1000000){
			printf("%s ", teen[num/1000000]);
			num/=1000000;
		}
		if(num >= 100000){
			printf("%s Lakhs ", digits[num / 100000]);
			num%= 100000;
		}
		if(num >= 20000){
			printf("%s ", tens[num/10000]);
			num %= 10000;
		}
		if(num >= 10000){
			printf("%s ", teen[num/10000]);
			num %= 10000;
		}
		if(num >= 1000){
			printf("%s Thousand ", digits[num/1000]);
			num%=1000;
		}
		if(num >= 100){
			printf("%s Hundred ", digits[num/100]);
			num%=100;
		}
		if(num >= 20){
			printf("%s ", tens[num/10]);
			num%=10;
		}
		if(num >= 10){
			printf("%s ", teen[num-10]);
			return 0;
		}
		if(num>0){
			printf("%s\n", digits[num]);
		}


	}
	return 0;
}


	
		
