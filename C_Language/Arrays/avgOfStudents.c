#include <stdio.h>

int main(){
	int n, sum = 0;
	float avg;
	printf("Enter number of Students: ");
	scanf("%d", &n);

	if(n == 0){
		printf("Invalid input!");
		return 1;
	}

	int marks[n];
	for(int i = 0; i < n; i++){
		printf("Enter marks of Student %d: ",i+1);
		scanf("%d", &marks[i]);
	}

	for(int j = 0; j < n; j++)
		sum += marks[j];
	
	avg =(float) sum / n;

	printf("The sum of %d students is %d and the avg is %.3f\n", n, sum, avg);

	return 0;
}

