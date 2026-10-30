#include <stdio.h>

int main(){
	int i = 74;
	float f = 3.14f;
	char s[] = "HelloMello";

	printf("%d %10d %-10d\n", i, i, i);
	printf("%.4f %10.4f %-10.4f\n", f, f, f);
	printf("%20s %-20s %20.5s\n", s, s, s);

	printf("Consider this\r statement\n");

	printf("%c %c %c\n", 65, '\101', '\x41');
	printf("%d\n", f);

	return 0;
}
