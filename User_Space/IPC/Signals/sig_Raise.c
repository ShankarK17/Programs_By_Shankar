#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void raise_handler(int sig){
	printf("Rasie signal Detected!\n");
	printf("FUnction Performing action...\n");
	sleep(2);
	printf("FUnction action done!\n");
}

int main(){
	if(signal(SIGUSR1, raise_handler) == SIG_ERR){
		printf("Error while setting signal handler\n");
		return 1;
	}

	printf("Main performing it's task...\n");
	sleep(1);
	printf("Main performing it's task...\n");
	if(raise(SIGUSR1) != 0){
		printf("Error while raising signal!\n");
		return 1;
	}

	printf("Main continue performing...\n");

	return 0;
}

		

