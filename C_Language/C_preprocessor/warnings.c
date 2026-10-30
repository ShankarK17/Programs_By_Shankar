//PROGRAM TO DEMONSTRATE FUNCTIONING OF PRAGMA FOR WARNING SUPPRESSING
#include <stdio.h>
 #pragma warn -rvl // -> for suppressing return value warning
 #pragma warn -par // -> for parameters missmatch
 #pragma warn -rch // -> for code control never reached 
int fun1(){
	int x = 5;
}
void fun2(int x){
	printf("I print\n");
}

int fun3(){
	int y = 6;
	return y;
	--y;
}

int main(){
	fun1();
	fun2(8);
	fun3();
	return 0;
}
