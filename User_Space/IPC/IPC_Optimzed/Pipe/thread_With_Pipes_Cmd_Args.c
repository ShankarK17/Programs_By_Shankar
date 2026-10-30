#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/wait.h>
struct Args{
	int *ip;
	int size;
	int (*fdp)[2];
};

void *parent_thread_fun(void *args){
	struct Args *pt_args = (struct Args *)args;
		printf("Parend PID: %d\n", getpid());
		if(close((*pt_args->fdp)[1]) == -1){ // closinf the writing end as we only need reading end to read from pipe
			printf("Error occured while closing the writing end of pipe of parent\n");
			return NULL;
		}
		int receive_oddsum;
		if(read((*pt_args->fdp)[0], &receive_oddsum, sizeof(receive_oddsum)) == -1){ // read function to read data from th pipe
			printf("Error occured while reading/receiving in parent process\n");
			return NULL;
		}
		if(close((*pt_args->fdp)[0]) == -1){
			printf("Error occured while closing the reading end of pipe in parent\n");
			return NULL;
		}
		int even_sum = 0;
		int n = pt_args->size;
		for(int i = 0; i < n; i++){
			if(pt_args->ip[i] % 2 == 0){
				even_sum += pt_args->ip[i];
			}
		}
		printf("Sum of even elements: %d\n",even_sum);
		int total_sum = receive_oddsum + even_sum;
		printf("Total Sum = %d\n", total_sum);
		free(pt_args);
		pthread_exit(NULL);
}

void *child_thread_fun(void *args){
	struct Args *ct_args = (struct Args *)args;
		printf("Child PID: %d\n", getpid());
		if(close((*ct_args->fdp)[0]) == -1){ // closing the unused reading end for child as we only require write end to send data in pipe
			printf("Error occured while closing the pipe reading end of child\n");
			return NULL;
		}
		int odd_sum = 0;
		int n = ct_args->size;
		for(int i = 0; i < n; i++){ 
			if(ct_args->ip[i] % 2 != 0){
				odd_sum += ct_args->ip[i];
			}
		}
		if(write((*ct_args->fdp)[1], &odd_sum, sizeof(odd_sum)) == -1){ // write function to write to the pipe
			printf("Error occured while writing/sending from child process\n");
			return NULL;
		}
		if(close((*ct_args->fdp)[1]) == -1){ // closing the writing end after the use
			printf("Error occured while closing the writing end of child\n");
			return NULL;
		}
		printf("Sum of Odd elements: %d\n", odd_sum);
		free(ct_args);
		pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	int elements = argc - 1;
	if(elements == 0){
		printf("No elements Passed!\n");
		return 1;
	}

	int i;
	int arr[elements];
	for(i = 0; i < elements; i++){
		arr[i] = atoi(argv[i+1]);
	}
	pthread_t child_thread, parent_thread;
	
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
		struct Args *child_args = malloc(sizeof(struct Args));
	       	if(child_args == NULL){
			printf("Not enought space!\n");
			return 1;
		}
		child_args->ip = arr;
		child_args->size = elements;
		child_args->fdp = &pipe_fd; 

		if(pthread_create(&child_thread, NULL, child_thread_fun, (void *)child_args) != 0){
			printf("Error while creating child thread\n");
			return 1;
		}
		pthread_join(child_thread, NULL);
	}
	else{ // PAREND PROCESS
		struct Args *parent_args = malloc(sizeof(struct Args));
		if(parent_args == NULL){
			printf("Not enougth space for parent args\n");
			return 1;
		}
		parent_args->ip = arr;
		parent_args->size = elements;
		parent_args->fdp = &pipe_fd;

		if(pthread_create(&parent_thread, NULL, parent_thread_fun, (void *)parent_args) != 0){
			printf("Error while creating parent thread\n");
			return 1;
		}

		pthread_join(parent_thread, NULL);
		wait(NULL);
	}
		
	return 0;
}







































