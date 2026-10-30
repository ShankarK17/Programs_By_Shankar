#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	int elements = argc - 1;

	int i;
	int arr[elements];
	for(i = 0; i < elements; i++){
		arr[i] = atoi(argv[i+1]);
	}

	int pipe_fd[2]; // file descriptor required to establish pipe connection
			// pipe_fd[0] represents reading/read end of the pipe
			// pipe_fd[1] represents writing/write end of pipe

	pid_t child_pid; // To store child variable

	if(pipe(pipe_fd) != 0){ // initiating pipe by providing the file_descriptor
		printf("Error occured while establishing pipe\n"); // ERROR CHECKS
		return 1;
	}

	child_pid = fork(); // forking to creating child process

	if(child_pid < 0){
	       printf("Error occured while creating child process\n");
       	       return 1;
	}

	if(child_pid == 0){ // CHILD PROCESS
		printf("Child PID: %d\n", getpid());
		if(close(pipe_fd[0]) == -1){ // closing the unused reading end for child as we only require write end to send data in pipe
			printf("Error occured while closing the pipe reading end of child\n");
			return 1;
		}
		int odd_sum = 0;
		for(i = 0; i < elements; i++){ 
			if(arr[i] % 2 != 0){
				odd_sum += arr[i];
			}
		}
		if(write(pipe_fd[1], &odd_sum, sizeof(odd_sum)) == -1){ // write function to write to the pipe
			printf("Error occured while writing/sending from child process\n");
			return 1;
		}
		if(close(pipe_fd[1]) == -1){ // closing the writing end after the use
			printf("Error occured while closing the writing end of child\n");
			return 1;
		}
		printf("Sum of Odd elements: %d\n", odd_sum);
	}
	else{ // PAREND PROCESS
		printf("Parend PID: %d\n", getpid());
		if(close(pipe_fd[1]) == -1){ // closinf the writing end as we only need reading end to read from pipe
			printf("Error occured while closing the writing end of pipe of parent\n");
			return 1;
		}
		int receive_oddsum;
		if(read(pipe_fd[0], &receive_oddsum, sizeof(receive_oddsum)) == -1){ // read function to read data from th pipe
			printf("Error occured while reading/receiving in parent process\n");
			return 1;
		}
		if(close(pipe_fd[0]) == -1){
			printf("Error occured while closing the reading end of pipe in parent\n");
			return 1;
		}
		int even_sum = 0;
		for(i = 0; i < elements; i++){
			if(arr[i] % 2 == 0){
				even_sum += arr[i];
			}
		}
		printf("Sum of even elements: %d\n",even_sum);
		int total_sum = receive_oddsum + even_sum;
		printf("Total Sum = %d\n", total_sum);
	}
	
	return 0;
}







































