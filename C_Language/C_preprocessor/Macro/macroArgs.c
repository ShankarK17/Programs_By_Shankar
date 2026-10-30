#include <stdio.h>
#define GREET(person_name) printf("hello %s, welcome to silicon signals LLP",person_name)
#define VALID(ch) (ch >= 'A' && ch <= 'Z')
// IMPORTANT TO INCLUDE THE MACRO EXPENSION WITHIN PARANTHESES 
int main()
{
	char letter;
	//GREET("Shankar\n");
	printf("Enter a character: ");
       scanf("%c", &letter);

	if(VALID(letter))
	 	printf("Capital Letter\n");
	else
		printf("Character other than Capital Letter\n");	
	

	return 0;
}

