#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun(void *args){ //thread function 
	//sleep(1); // blocks the thread exection for 1 sec 
	printf("Thread function executing...\n");
	sleep(1);
	printf("Done execution!\n");
	return NULL;
}

int main(){
	pthread_t thread_id; // declaration of thread variable to store thread ID
	int flag;

	printf("Started!\n");

	flag = pthread_create(&thread_id, NULL, thread_fun, NULL); // function to create thread
	// Parameter(Address of Thread var, attributes for configuration, Function to be called, Arguments for function(void Pointer))

	if(flag != 0){
		printf("Couldn't create thread\n");
		return 1;
	}

	/*
	 * Main code will go there which we want to execute parallelly with the thread
	 * if we write pthread_join() the main execution will halt untill thread completes it's work
	 * but as the printf statment is written before join the printf statement executed anyway
	 */

	// But there the race condition will occur as both these main & background thread wants to execute on core
	printf("Main[main thread]: Doing it work parallelly...\n");

	pthread_join(thread_id, NULL); // wait till thread with specified thread id completes it execution

	return 0;
}
