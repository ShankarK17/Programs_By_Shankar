#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]){
	int pid = atoi(argv[1]);

	if(kill(pid, SIGUSR1) != 0){
		printf("Error while ending signal!\n");
		return 1;
	}

	printf("Signal Sent!\n");
	return 0;
}
