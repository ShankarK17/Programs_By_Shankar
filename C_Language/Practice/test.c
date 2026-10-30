#include <stdio.h>
int main(int argc, char *argv[]){
	char *str = "Hello";
	char *str1 = "Hello";

	//printf("Addres of str: %u\n", str);
	//printf("Addres of str1: %u\n", str1);
	printf("argv[1]: %s\n", argv[1]);
	printf("Address of argv: %u\n", &argv[1]);
	printf("Address of argv: %u\n", &argv[2]);
	//argv[1][0] = 'M';
	//argv[1][2] = 'h';
	//printf("%s\n", argv[1]);
	char *s = argv[1];
	printf("s = %s\n", s);
	s = "Mello";
	argv[1] = "ZeptoFellow";
	printf("%s\n", argv[2]);
	printf("s = %s\n", s);
	printf("argv[1]: %s\n", argv[1]);
	printf("Address of argv: %u\n", &argv[1]);
	printf("Address of argv: %u\n", &argv[2]);
	return 0;
}
