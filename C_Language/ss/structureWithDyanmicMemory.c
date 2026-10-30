#include <stdio.h>
#include <stdlib.h>

struct point {
	int x;
	int y;
};

struct point *fun(int, int);
void display(struct point *);

int main(){
	struct point *sp;
	sp = fun(5,6);
	display(sp);
	free(sp);

	return 0;
}

struct point *fun(int a, int b){
	struct point *temp = (struct point *)malloc(sizeof(struct point));
	temp->x = a*2;
	temp->y = b+5;
	return temp;
}

void display(struct point *help){
	printf("%d %d\n", help->x, help->y);
}
