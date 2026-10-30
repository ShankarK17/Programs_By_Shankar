#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


void *square(void *args){
	 long data = (long)args;
	 
	 data = data * data;

	 pthread_exit((void *)data);
}

int main(){
	pthread_t thread;
	void *result;

	long number = 9;

	if(pthread_create(&thread, NULL, square, (void *)number) != 0){
		printf("Fail to create thread\n");
		return 1;
	}

	pthread_join(thread, &result);

	long output = (long)result;

	printf("The Result Square value is : %ld\n", output);

	return 0;
}






       		
