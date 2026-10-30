#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct st {
	char c;//c = a
	int i;//i = 10
	char *p; //p = silicon 
	int j; // j = 20
};

int main(){
	struct st *sp;
	sp = (struct st *)calloc(1,sizeof(struct st));
	printf("Size of struct: %ld\n", sizeof(struct st));

	sp->c = 'a';
	sp->i = 10;
	sp->p = (char *)malloc(8 * sizeof(char));
	sp->p = "Silicon";	
	sp->j = 20;

	printf("%c %d %s %d\n", sp->c, sp->i, sp->p, sp->j);




	return 0;
}

	

	

