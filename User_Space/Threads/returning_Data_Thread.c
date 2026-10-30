#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Triangle{
	int len;
	int bre;
	double area;
};

void *cal_Area(void *args){
	struct Triangle *stptr = (struct Triangle *)args;

	struct Triangle *result = malloc(sizeof(struct Triangle));
	if(result == NULL){
		printf("No memory!\n");
		free(stptr);
		exit(1);
	}

	result->len = stptr->len;
	result->bre = stptr->bre;
	result->area = result->len * result->bre;

	free(stptr);

	return ((void *)result);
}

int main(){
	pthread_t thread;
	struct Triangle *tdata = malloc(sizeof(struct Triangle));
	if(tdata == NULL){
		printf("No memory!\n");
		return 1;
	}

	struct Triangle *resTri;

	tdata->len = 9;
	tdata->bre = 5;
	tdata->area = 0;

	if(pthread_create(&thread, NULL, cal_Area, (void *)tdata) != 0){
		printf("Fail to create Thread\n");
		free(tdata);
		return 1;
	}

	pthread_join(thread, (void **)&resTri);

	printf("Area of traingle = %.2lf\n", resTri->area);

	free(resTri);

	return 0;
}





