#include <stdio.h>
int main(){
	int n = 4;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<2*n; j++){
			if(j == n-(i-1) || j == n+(i-1))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	for(int k = n-1; k > 0; k--){
		for(int l = 2*n-1; l > 0; l--){
			if(l == n+(k-1) || l == n-(k-1))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;

}
