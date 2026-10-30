#include <stdio.h>
int main(){
	int i = 23;
	float pi = 31.4;
	char c = 's';
	char str[50];
	printf("Output from printf function: %d %f %c\n", i, pi, c);
	sprintf(str, "Output from sprintf function: %d %f %c", i, pi, c);

	printf("%s\n", str);
	char input[100];
	printf("\nEnter a string consist of Number_Value, character, float(, seperated): ");
	scanf("%[^\n]s", input);

	int num;
	char ch;
	float f;
	int noOfitems = sscanf(input, "%d, %c, %f", &num, &ch, &f);
	printf("Number = %d\n", num);
	printf("Character = %c\n", ch);
	printf("Float = %f\n", f);
	

	return 0;
}	
