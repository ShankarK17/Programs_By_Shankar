#include <stdio.h>
#include <string.h>
int main(){
	char words[][50] = {
		"This is elon musk",
		"I'm ironman",
		"I can do this all day"};
	
	char *ptr, temp, *help;
	for(int i = 0; i < 3; i++){
		ptr = words[i];
		int len = strlen(words[i]);
		help = ptr + len - 1;
		int i = 0;
		while(i <= len/2){
			temp = *ptr;
			*ptr = *help;
			*help = temp;
			ptr++;
			help--;
			i++;
		}
	}

	for(int i = 0; i<3; i++)
		printf("%s\n", words[i]);	

	return 0;
}	
	
