#include <stdio.h>

int main(){
	int num, temp , bi[8];
	printf("Enter a number: ");
	scanf("%d", &num);
	int i = 0;
	temp = num;
	while(num > 0){
		bi[i] = num % 2;
		num /=2;
		i++;
	}

	printf("The binary equivalent of %d is : ", temp);
	for(int j = i-1; j >= 0; j--)
		printf("%d", bi[j]);

	printf("\n");

	return 0;
}
