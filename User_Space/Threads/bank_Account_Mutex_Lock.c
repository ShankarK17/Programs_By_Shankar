#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int balance = 100;
pthread_mutex_t lock;

void *withdraw(void *args){
	int* amount = (int *)args;
	pthread_mutex_lock(&lock); // enables a lock which allow only one thread to end this section of code at a time
	if(balance >= *amount){
		usleep(10000); // sleep to mimic condition that CPU core switch thread 1 and thread 2
		balance -= *amount;
		printf("Available balance: %d\n", balance);
		pthread_mutex_unlock(&lock); // unlocks the lock so the other thread can enter
					     // only after the entered thread exits the critical section
	}
	else{
		printf("Insufficeint balance to initiate withdrawl\n");
	}
	return NULL;
}



int main(){
	pthread_t thread1, thread2;
	pthread_mutex_init(&lock, NULL); // initiating the mutex
	int value = 100;
	if(pthread_create(&thread1, NULL, withdraw, &value) != 0){
		printf("Thread 1 creation failed!\n");
		return 1;
	}
	if(pthread_create(&thread2, NULL, withdraw, &value) != 0){
		printf("Thread 2 creation failed!\n");
		return 1;
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&lock); // destroying the mutex it done it's work

	return 0;
}



