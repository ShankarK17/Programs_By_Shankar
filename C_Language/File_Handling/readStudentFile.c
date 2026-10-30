#include <stdio.h>
#include <stdlib.h>
struct student {
	char name[30];
	char dept[20];
} stu;
int main(){
	FILE *fp;
	fp = fopen("student.list", "r");
	if(fp == NULL){
		printf("Error occured while opening the file");
		exit(1);
	}
	printf("Name\tDepartment\n");
	while(fscanf(fp, "%s %s", stu.name, stu.dept) != EOF)
		printf("%s\t%s\n", stu.name, stu.dept);
	fclose(fp);

	return 0;
}

