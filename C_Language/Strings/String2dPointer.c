#include <stdio.h>
int main(){
	char *avengers[] = {
		"Ironman", "Captain", "Hulk",
		"Hawkeye", "Thor", "Spiderman"};

	char *new = "Captain America";

	avengers[1] = new;
	int i = 0;
	while(i < 6){
		printf("%s\n", avengers[i]);
		i++;
	}


	return 0;
}
