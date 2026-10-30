#include <stdio.h>
struct student {
	int rolln;
	char name[30];
	char department[20];
	char course[20];
	int year;
};

void displaystudent_year(struct student *, int);
void getstudent_rolln(struct student *, int);

int main(){
	struct student s[10];
	int i;
	for(i = 0; i<=9; i++){
		printf("Expected Format: Name, Department, Course, Year of Joining:-\n");
		printf("Enter details of Student %d: ", i+1);
		s[i].rolln = i+1;
		scanf(" %s %s %s %d", s[i].name, s[i].department, s[i].course, &s[i].year);
	}

	int checkYear, checkRoll;
	printf("Enter a Year to check student joined: ");
	scanf("%d", &checkYear);

	displaystudent_year(s, checkYear);

	printf("Enter roll number of student: ");
	scanf("%d", &checkRoll);

	getstudent_rolln(s, checkRoll);
	
	return 0;
}

void displaystudent_year(struct student *sp, int y){
	struct student *cp;
	int flag = 0;
	for(cp = sp; cp <= sp+9; cp++){
		if(cp->year == y){
			printf("%s Joined in Year %d\n", cp->name, y);
			flag = 1;
		}
	}
	if(!flag){
		printf("No Match Found!\n");
	}
	printf("\n");
}



void getstudent_rolln(struct student *sp, int r){
	if(r > 10 || r == 0){
		printf("Invalid roll number!\n");
		return 0;
	}
	struct student *cp;
	for(cp = sp; cp <= sp+9; cp++){
		if(cp->rolln == r){
			printf("Student Name: %s\t Department: %s\t Course: %s\t Year Joined: %d\n", cp->name, cp->department, cp->course, cp->year);
			break;
		}
	}
}



