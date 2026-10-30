#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_fun(void *args){
	printf("Thread Id: %lu\n", pthread_self()); //pthread_self() return the thread id of the calling thread
						    //it is not same as gettid() as gettid() returns thread id that of kernel level
						    //whereas pthread_self return thread id at posix user level/
	printf("Thread Function executing...\n");
	sleep(1); // making it sleep to mimic some task execution.
	printf("Done execution!\n");
	pthread_exit(NULL);
}

int main(){
	pthread_t thread_id;
	pthread_attr_t thread_attr; //pthread_attr variable require to set specific attributes/configurations like
				    //stack size, detch state i.e Joinable or detachable etc.

	if(pthread_attr_init(&thread_attr) != 0){ // error checks for initialting attr
		printf("Couldn't initiate Attributes for thread!\n");
		return 1;
	}

	if(pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED) != 0){
		printf("Couldn't set detach state attribute!\n"); // setting thread to be detachable means the calling thread won't wait for
								  // thread to terminate it will be terminate and the resources will be freed automatically
		return 1;
	}

	if(pthread_create(&thread_id, &thread_attr, thread_fun, NULL) != 0){
		printf("Couldn't create thread with detach attribute!\n");
		pthread_attr_destroy(&thread_attr);
		return 1;
	}

	sleep(2); // blocking main thread so that custom  thread can finish it's execution otherwise, the main will terminate and 
		  // the custom thread won't be able to complete it's execution.

	pthread_attr_destroy(&thread_attr); // destroying the attributes to freed the resources.
	printf("Program exiting!\n");
	return 0;
}



