#include <stdio.h>
struct car{
	char model[20];
	int year;
};
void display1(char *, int);
void display2(struct car);
void display3(struct car *);

int main(){
	struct car c1 = {"Mustang", 1969};

	display1(c1.model, c1.year);
	display2(c1);
	display3(&c1);

	return 0;
}

void display1(char *name, int y){
	printf("Model = %s\t Year = %d\n", name, y);
}

void display2(struct car c){
	printf("Model = %s\t Year = %d\n", c.model, c.year);
}

void display3(struct car *cp){
	printf("Model = %s\t Year = %d\n", cp->model, cp->year);
}


		
