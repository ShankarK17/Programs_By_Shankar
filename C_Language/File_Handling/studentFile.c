#include <stdio.h>
#include <stdlib.h>
struct student {
	char name[30];
	char dept[20];
};

int main(){
	FILE *fp;
	fp = fopen("student.list", "w");
	struct student stu;

	int i, n;
	printf("Enter number of students: ");
	scanf("%d", &n);

	for(i = 0; i<n; i++){
		printf("Enter Student name & Department: ");
		scanf("%s %s", stu.name, stu.dept);
		fprintf(fp, " %-20s\t %10s\n", stu.name, stu.dept);
	}

	return 0;
}
