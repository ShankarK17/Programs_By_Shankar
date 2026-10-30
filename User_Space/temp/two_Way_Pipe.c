#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){
	char child_msg[] = "Hello From child";
	char parent_msg[] = "Hello From parent";

	char buffer[50];

	int ctop[2], ptoc[2]; // Two Pipe for both process i.e 4 File descriptor on both sides
	// Child Writes -> Parent Reads
	// Parent Writes -> Child Reads
	pid_t child_pid;
	
	if(pipe(ctop) != 0){
		printf("Error occured while creating pipe 1\n");
		return 1;
	}

	if(pipe(ptoc) != 0){
		printf("Error occured while creaing pipe 2\n");
		return 1;
	}

	child_pid = fork();

	if(child_pid < 0){
		printf("Fail to create child process\n");
		return 1;
	}

	if(child_pid == 0){
		printf("Child PID: %d\n", getpid());
		
		// Closing unneccessary file desciptors of both pipe of both processes
		if(close(ctop[0]) == -1){
			printf("Error occured while closing reading end of Pipe 1 in child\n");
			return 1;
		}
		if(close(ptoc[1]) == -1){
			printf("Error occured while closing Pipe 2 writing end in child\n");
			return 1;
		}
		
		if(read(ptoc[0], buffer, sizeof(buffer)) == -1){ // 
			printf("Error occured while reading from Pipe 2 in child\n");
			return 1;
		}
		printf("Received \"%s\" from Child\n", buffer);

		if(write(ctop[1], child_msg, sizeof(child_msg)) == -1){
			printf("Error occured while writing in Pipe 1 in child\n");
			return 1;
		}
		printf("Sent \"%s\" from Child\n", child_msg);

		if(close(ctop[1]) == -1){
			printf("Error occured while closing writing end of Pipe 1 in child\n");
			return 1;
		}
		if(close(ptoc[0]) == -1){
			printf("Error occured while closing Pipe 2 reading end in child\n");
			return 1;
		}
	}
	else{
		printf("Parent PID: %d\n", getpid());
		if(close(ctop[1]) == -1){
			printf("Error occured while closing writing end of Pipe 1 in Parent\n");
			return 1;
		}
		if(close(ptoc[0]) == -1){
			printf("Error occured while closing Pipe 2 reading end in Parent\n");
			return 1;
		}

		if(write(ptoc[1], parent_msg, sizeof(parent_msg)) == -1){
			printf("Error occured while writing in Pipe 2 in Parent\n");
			return 1;
		}
		printf("Sent \"%s\" from Parent\n", parent_msg);
		
		if(read(ctop[0], buffer, sizeof(buffer)) == -1){
			printf("Error occured while reading from Pipe 1 in Parent\n");
			return 1;
		}
		printf("Received \"%s\" from Parent\n", buffer);
		if(close(ctop[0]) == -1){
			printf("Error occured while closing reading end of Pipe 1 in Parent\n");
			return 1;
		}
		if(close(ptoc[1]) == -1){
			printf("Error occured while closing Pipe 2 writing end in Parent\n");
			return 1;
		}
	}
	return 0;
}








		

































