#include <stdio.h>
#include <pthread.h>

int flag = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *func_worker(void *args){
	pthread_mutex_lock(&lock);
	printf("Worker Waiting...\n");

	while(flag == 0){
		pthread_cond_wait(&cond, &lock);
	}

	printf("Worker doing work...\n");
	pthread_mutex_unlock(&lock);

	return NULL;
}

void *func_boss(void *args){
	pthread_mutex_lock(&lock);
	flag = 1;
	printf("FLag assigned\n");
	pthread_mutex_unlock(&lock);

	pthread_cond_signal(&cond);
	printf("Boss sent signal\n");

	return NULL;
}

int main(){
	pthread_t w_thread, b_thread;

	if(pthread_create(&w_thread, NULL, func_worker, NULL) != 0){
		printf("Fail to create worker thread\n");
		return 1;
	}

	if(pthread_create(&b_thread, NULL, func_boss, NULL) != 0){
		printf("Fail to create boss thread\n");
		return 1;
	}

	pthread_join(w_thread, NULL);
	pthread_join(b_thread, NULL);

	return 0;
}























