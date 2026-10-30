#include <stdio.h>
int i = 0;
void val();

int main()
{
	printf("i in main %d\n", i);
	i++;
	val();
	printf("again i in main %d\n", i);
	val();
	return 0;
}

void val()
{
	i = 100;
	printf("i in void %d\n", i);
	i++;
}
