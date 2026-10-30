#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
void sigact_handler(int signum){
	char *msg = "Signal Dectected! Terminating...\n";
	write(STDOUT_FILENO, msg, strlen(msg));
	exit(1);
}

int main(){
	struct sigaction sa;

	sa.sa_handler = sigact_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if(sigaction(SIGINT, &sa, NULL) != 0){
		printf("Error while setting sigaction!\n");
		return 1;
	}

	while(1){
		printf("Hahaha Running....\n");
		sleep(1);
	}

	return 0;
}

