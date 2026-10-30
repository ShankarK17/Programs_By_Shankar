#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	pid_t child_pid;

	printf("Parent ID: %d\n", getpid());

	switch(child_pid = fork()){
		case -1:
			printf("Fork Failed\n");
			return 1;
		case 0:
			printf("Child ID: %d\n", getpid());
			printf("Executing command %s %s...\n", argv[1], argv[2]);
			//char *args[] = {"ls", "-l", NULL};
			execlp(argv[1], argv[1], argv[2], NULL);

			perror("exec failed");
			exit(1);
		default:
			int status;
			pid_t pid = wait(&status);
			printf("Parent PID: %d", getppid());
			//int status;
			printf("Parent waiting for child....\n");
			//pid_t pid = wait(&status);
			printf("Parent finished waiting, Child completed excution\n");

			if(WIFEXITED(status)){
				printf("Child exited with code: %d\n", WIFEXITED(status));
			}
	}

	return 0;
}



