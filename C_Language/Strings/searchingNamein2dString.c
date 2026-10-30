#include <stdio.h>
#include <string.h>
int main(){
	char names[6][20] = {"Ironman", "Hulk", "Thor",
			     "Captain", "Hawkeye", "Natasha"
	};

	char name[20];
	printf("Enter your name: ");
	scanf("%s", name);

	for(int i = 0; i<5; i++){
		if(strcmp(&names[i][0], name) == 0){
				printf("Welcome to Avenger towers, %s\n", name);
				return 0;
				}
	}
	printf("Go away, Stranger!");

	return 0;
}
