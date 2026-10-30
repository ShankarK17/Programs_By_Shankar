#include <stdio.h>

int main(){
	struct policy {
		char holdername[30];
		unsigned gender: 1;
		unsigned status: 1;
		char polname[20];
		int duration;
	};

	enum gen{
		male, female
	};

	enum stat{
		minor,
		major
	};

	struct policy p[5];
	int i;
	char g, s;
	printf("Format: Name Gender(m/f) Status(u/a) Policy_Name Duration_Of_Policy\n");
	for(i = 0; i<5; i++){
		printf("Enter your Policy details: ");
		scanf(" %s %c %c %s %d",p[i].holdername, &g, &s, p[i].polname, &p[i].duration);
		if(g == 'm')
			p[i].gender = male;
		else
			p[i].gender = female;
		if(s == 'u')
			p[i].status = minor;
		else
			p[i].status = major;
	}

	printf("Policy Info:-\n");
	for(i = 0; i<5; i++){
		printf("Policy holdername: %-10s\t", p[i].holdername);
		printf("Gender: ");
		if(p[i].gender == 1)
			printf("Female\t");
		else
			printf("Male\t");
		printf("Status: ");
		if(p[i].status == 1)
			printf("Major\t");
		else
			printf("Minor\t");
		printf("Policy Provider: %-10s\t", p[i].polname);
		printf("Policy Duration: %-5d Years\n", p[i].duration);
	}

	return 0;
}

