#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int balance = 100;

void *withdraw(void *args){
	int* amount = (int *)args;
	if(balance >= *amount){
		usleep(10000); // sleep to mimic condition that CPU core switch thread 1 and thread 2
		/*
		 * when thread 2 enters the function it checks the same condition i.e is currently balance > than amount
		 * and which is true as thread 1 haven't updated the balance as it halt before performing the substaction logic
		 * and procceds to execute the same operation with old value
		 */	
		balance -= *amount;
		printf("Available balance: %d\n", balance);
	}
	else{
		printf("Insufficeint balance to initiate withdrawl\n");
	}
	return NULL;
}



int main(){
	pthread_t thread1, thread2;
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

	return 0;
}



