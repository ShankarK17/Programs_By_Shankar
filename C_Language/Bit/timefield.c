#include <stdio.h>

void displaytime(unsigned short int);

int main(){
	unsigned short int time;
	printf("Enter the time in 2-byte format: ");
	scanf("%hu", &time);

	displaytime(time);

	return 0;
}

void displaytime(unsigned short int tem){
	unsigned short int hours, minutes, seconds, help;
	hours = tem >> 11;
	help = tem >> 5;
	help = help << 10;
	minutes = help >> 10;
	help = tem << 11;
	seconds = help >> 11;

	printf("For time %hu = %hu HOURS: %hu MINUTES: %hu SECONDS\n", tem, hours, minutes, seconds);

}



