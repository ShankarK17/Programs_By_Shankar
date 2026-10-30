#include <stdio.h>
#define SIZE 3

int main(){
	char box[SIZE][SIZE] = {0};
	int i,j, row, col;
	int isOn = 1;

	printf("\n WELCOME! TO GAME O & X\n");



	do{
		printf("Enter row & col number to play: ");
		scanf("%d %d", &row, &col);

		if(box[row-1][col-1] == 'x' || box[row-1][col-1] == 'o')
			printf("Cant place your move, already filled")
		else{
			box[row-1][col-1] = 'x';
			for(i = 0; i<SIZE; i++){
				for(j=0; j<SIZE; j++){
					if()
			

		

	return 0;
}
