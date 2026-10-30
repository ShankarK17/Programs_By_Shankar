#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct car{
	char *model;
	int year;
	char fuel;
	float mileage;
};


int main(int argc, char *argv[]){
	if(argc != 5){
		printf("Invalid number of arguments!");
		exit(1);
	}

	struct car *sp = (struct car *)malloc(sizeof(struct car));
	if(sp == NULL){
		printf("Memory Not available!");
		exit(1);
	}
	sp->model = (char *)malloc(strlen(argv[1])+1);
	if(sp->model == NULL){
		printf("Required space not available!");
		free(sp);
		exit(1);
	}
	strcpy(sp->model,argv[1]);
	sp->year = atoi(argv[2]);
	sp->fuel = argv[3][0];
	sp->mileage = atof(argv[4]);

	printf("Car Model: %s\tYear: %d\tFuel: %c \tMileage: %.2f\n", sp->model, sp->year, sp->fuel, sp->mileage);
	free(sp->model);
	free(sp);

	return 0;
}



	
	



	
