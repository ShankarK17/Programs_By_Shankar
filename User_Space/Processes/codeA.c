#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	pid_t child1_pid;
	int compile_status;

	printf("Parent PID: %d\n", getpid());

	switch(child1_pid = fork()){
		case -1:
			printf("Fork 1 Failed\n");
			return 1;
		case 0:
			printf("Child1 PID: %d\n", getpid());
			printf("File codeB.c compiling...\n");
			char *compiling_args[] = {"gcc", "codeB.c", "-o", "programB", NULL};
			execvp(compiling_args[0], compiling_args);

			perror("Exec for compiling failed\n");
			exit(1);
		default:
			wait(&compile_status);

			if(WIFEXITED(compile_status)){
				int check = WEXITSTATUS(compile_status);
				if(check == 0){
					printf("codeB.c compiled successfully\n");
				}
				else{
					printf("Couldn't complete compilation\n");
					exit(EXIT_FAILURE);
				}
			}
			else{
				printf("Child Process Crashed\n");
				exit(EXIT_FAILURE);
			}
	}

	pid_t child2_pid;
	int execute_status;

	switch(child2_pid = fork()){
		case -1:
			printf("Fork 2 failed\n");
			return 1;
		case 0:
			printf("Child2 PID: %d\n", getpid());
			printf("Executing program B...\n");
			char *executing_args[] = {"./programB", argv[1], NULL};
			execvp(executing_args[0], executing_args);

			perror("Exec for executing failed\n");
			exit(1);
		default:
			wait(&execute_status);

			if(WIFEXITED(execute_status)){
				printf("Program B executed successfully\n");
			}
			else{
				printf("Program B execution Failed\n");
			}
	}
	return 0;
}


