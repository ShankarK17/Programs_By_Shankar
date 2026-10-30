#include <stdio.h>

#define UPPER(ch) (ch >=65 && ch <=90? 1: 0)
#define LOWER(ch) (ch >= 97 && ch <= 122? 1: 0)
#define ALPHA(ch) (UPPER(ch) || LOWER(ch))
#define BIGGER(x, y) (x>y? x: y)

int main()
{
	char ch;
	printf("Enter a character to check: ");
	scanf("%c", &ch);

	if(UPPER(ch) == 1)
		printf("Capital Letter\n");
	if(LOWER(ch) == 1)
		printf("Lower letter\n");

	if(ALPHA(ch) != 1)
		printf("Not a Alphabet\n");
	else
		printf("Alphabet\n");

	int a, b;
	printf("Enter two number to determine greatest: ");
	scanf("%d %d", &a, &b);
	int res = BIGGER(a, b);
	printf("%d is greater\n", res);

	return 0;
}

