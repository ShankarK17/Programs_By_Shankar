#include <stdio.h>

int main(){
	char str[] = "Mumbai";
	char *sptr = "Bombay";

	printf("Size of str = %ld\t", sizeof(str));
	printf("Size of sptr = %ld\n", sizeof(*&sptr));

	str[0] = 'B';
	printf("%s\n", str);
	sptr = "Pune";
	printf("%s\n", sptr);

	return 0;
}
