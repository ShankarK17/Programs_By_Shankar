#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Std{
	char *msg;
	int value;
};

void *displayData(void *args){
	struct Std *stptr = (struct Std *)args;

	printf("Message = %s\tValue = %d\n", stptr->msg, stptr->value);

	free(stptr);

	pthread_exit(NULL);
}

int main(){
	pthread_t thread;

	struct Std *data = malloc(sizeof(struct Std));
	if(data == NULL){
		printf("No memory!\n");
		return 1;
	}

	data->msg = "Hello from main";
	data->value = 17;

	if(pthread_create(&thread, NULL, displayData, (void *)data) != 0){
		printf("Fail to create thread\n");
		free(data);
		return 1;
	}

	pthread_join(thread, NULL);

	return 0;
}
