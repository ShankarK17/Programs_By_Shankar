#include <stdio.h>

int main(){
	char p[] = "Mumbai";
	p[0] = 'B';
	char *str = "Bombay";
	str = "Pune";
	printf("%s\a", p);


	return 0;
}
