#include <stdio.h>

int main(){
	struct books{
		char name[50];
		int price;
		int pages;
	};

	struct books b[3];
	int i = 0;
	do{
		printf("Enter name, price & no. of pages of book %d: ", i+1);
		scanf(" %s %d %d", b[i].name, &b[i].price, &b[i].pages);
		i++;
	}while(i<3);

	for(int j = 0; j<3; j++){
		printf("Details of book %d:Name: \"%s\" Price: %d Pages: %d\n",j+1, b[j].name, b[j].price, b[j].pages);
	}


	return 0;
}
