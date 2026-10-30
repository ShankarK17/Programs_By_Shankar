#include <stdio.h>

struct date{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 12;
};

int main(){
	struct date d[5];
	int i, j;
	int da, m, y;
	printf("Format of date: DD-MM-YYYY\n");
	for(i = 0; i<5; i++){
		printf("Enter date of joining of Employee %d: ",i+1);
		scanf("%d-%d-%d", &da, &m, &y);
		d[i].day = da;
		d[i].month = m;
		d[i].year = y;
	}

	for(i = 0; i<5; i++){
		for(j = 0; j<5-i-1;j++){
			if(d[j].year > d[j+1].year){
				struct date temp = d[j];
				d[j] = d[j+1];
				d[j+1] = temp;
			}
		}
	}



	for(i = 0; i<5; i++){
		printf("Date of Joining: %d/%d/%d\n", d[i].day, d[i].month, d[i].year);
	}

	return 0;
}










	
	
