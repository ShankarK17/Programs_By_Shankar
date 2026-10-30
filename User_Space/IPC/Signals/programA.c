#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig){
	printf("====Signal received!====\n");
}

int main(){
	
	if(signal(SIGUSR1, signal_handler) == SIG_ERR){
		printf("Error while setting signal handler\n");
		return 1;
	}
	printf("Process ID: %d\n", getpid());
	while(1){
		printf("Do Not Interrupt!\n");
		sleep(1);
	}
	return 0;
}

