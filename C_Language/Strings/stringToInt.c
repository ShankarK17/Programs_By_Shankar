#include <stdio.h>
#include <string.h>

int main(){
	char str[10];
	printf("Enter a number in string format: ");
	scanf("%s", str);

	char *sp = str;
	int num = 0;

	while(*sp != '\0'){
		int value = (int) (*sp-48);
		if(value < 0 || value > 9){
			printf("Input string is not a numerical value!\n");
			return 0;
		}
		else{
			num = num * 10 + value;
			sp++;
		}
	}

	printf("The number is %d\n", num);

	return 0;
}


