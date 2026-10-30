#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date {
	unsigned day: 5;
	unsigned month: 4;
	unsigned year: 12;
};

typedef struct Employee {
	int code;
	char *name;
	struct date *dp;
} EMP;

int main(int argc, char *argv[]){
	int n = argc - 1;
	EMP *ep;
        ep = (EMP *)malloc(n*sizeof(EMP));
	if(ep == NULL){
		printf("Not enough space available!");
		exit(1);
	}

	int i;
	for(i = 0; i<n; i++){
		printf("Enter details of employee Name %s\n", argv[i+1]);
		printf("Employee code & Date 0f Joining(dd-mm-yyyy): ");
		ep[i].name = (char *)malloc(strlen(argv[i+1])+1);
		if((ep+i)->name == NULL){
			printf("No space available");
			exit(1);
		}	
		strcpy((ep+i)->name, argv[i+1]);
		ep[i].dp = (struct date *)malloc(sizeof(struct date));
		if((ep+i)->dp == NULL){
			printf("Not enough memory");
			exit(1);
		}
		int d, m, y;
		scanf("%d %d-%d-%d", &ep[i].code, &d, &m, &y);
		ep[i].dp->day = d;
		ep[i].dp->month = m;
		ep[i].dp->year = y;
	}
	int dd, mm, yy;
	printf("\nEnter current date(dd-mm-yyyy): ");
	scanf("%d-%d-%d", &dd, &mm, &yy);

	printf("Employee with tenure greater than 3 are:-\n");
	for(i = 0; i<n; i++){
		if(yy - ep[i].dp->year >= 3){
			printf("Name: %s \t Emp code: %d\n", ep[i].name, ep[i].code);
		}
	}

	for(i = 0; i<n; i++){
		free(ep[i].name);
		free(ep[i].dp);
	}
	free(ep);
		
	return 0;
}
