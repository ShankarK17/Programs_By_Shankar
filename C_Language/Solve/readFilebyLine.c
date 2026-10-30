#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp = fopen("Lines.txt", "r");
	if(fp == NULL){
		printf("Couldn't load file");
		exit(1);
	}



