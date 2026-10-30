#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void *enter_Toll(void *args){
	int car = *(int *)args;

	printf("Car %d waiting at toll\n", car);
	sem_wait(&sem);

	printf("Car %d entering the toll\n",  car);
	sleep(1);

	printf("Car %d leaving the toll\n", car);
	sem_post(&sem);

	return NULL;
}

int main(){
	pthread_t threads[3];

	int cars[3] = {1, 2, 3};

	sem_init(&sem, 0, 2); 

	for(int i = 0; i<3; i++){
		if(pthread_create(&threads[i], NULL, enter_Toll, &cars[i]) != 0){
			printf("Failed to create thread %d", i+1);
			return 1;
		}
	}

	for(int j = 0; j<3; j++){
		pthread_join(threads[j], NULL);
	}

	sem_destroy(&sem);

	return 0;
}
