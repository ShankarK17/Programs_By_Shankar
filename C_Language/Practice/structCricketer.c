#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Cricketer {
	char *name;
	int age;
	int matches;
	float avg;
};

int main(int argc, char *argv[]){
	int n = argc - 1;
	struct Cricketer *sp;
        sp = (struct Cricketer *)malloc(n*(sizeof(struct Cricketer)));
	if(sp == NULL){
		printf("Not enough space available");
		exit(1);
	}
	int i, j;
	for(i = 0; i<n; i++){
		printf("Enter details of Cricketer %s\nAge, No_of_Matche & Average_runs: ", argv[i+1]);
		sp[i].name = (char *)malloc(strlen(argv[i+1])+1);
		if((sp+i)->name == NULL){
			printf("Not enough space\n");
			free(sp);
			exit(1);
		}
		strcpy((sp+i)->name, argv[i+1]);
		sp[i].name = argv[1];
		scanf("%d %d %f", &sp[i].age, &sp[i].matches, &sp[i].avg);
	}
/*
	for(i = 0; i<n; i++){
		printf("Cricketer : %-12s\tAge: %2d\tMatches: %3d\tAverage: %3.2f\n", sp[i].name, sp[i].age, sp[i].matches, sp[i].avg);
	}	
	*/
	for(i = 0; i<n; i++){
		for(j = 0; j<n-i-1; j++){
			if(sp[j].avg <= sp[j+1].avg){
				struct Cricketer temp = sp[j];
				sp[j] = sp[j+1];
				sp[j+1] = temp;
			}
		}
	}

	FILE *fp;
	fp = fopen("CricketerInfo.text", "w+");
	if(fp == NULL){
		printf("Error while opening the file!");
		exit(1);
	}
	fprintf(fp, "Rank\tNAME\t Age\t Matches\t Average\n");
	for(j = 0; j<n; j++){
		fprintf(fp, "%d\t %-12s\t %2d\t %3d\t %3.1f\n",j+1, sp[j].name, sp[j].age, sp[j].matches, sp[j].avg);
	}
	fclose(fp);
	for(i = 0; i<n; i++){
		free(sp[i].name);
	}
	free(sp);



	return 0;
}

