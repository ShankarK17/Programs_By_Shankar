#include <stdio.h>
#include <pthread.h>

void *functionA(void *args){
	//for(int i = 0; i<100; i++){
	printf("Called Function A\n");
	//}
	return NULL;
}

void *functionB(void *args){
	//for(int j = 0; j<100; j++){
	printf("Called Function B\n");
	//}
	return NULL;
}

int main(){
	pthread_t thread1, thread2;
	printf("===========START==============\n");
	if(pthread_create(&thread1, NULL, functionA, NULL) != 0){
		printf("Fail to create thread 1\n");
		return 1;
	}
	
	if(pthread_create(&thread2, NULL, functionB, NULL) != 0){
		printf("Fail to create thread 2\n");
		return 1;
	}
	pthread_join(thread2, NULL);
	pthread_join(thread1, NULL);
	//pthread_join(thread2, NULL);
	printf("=========END============\n");
	return 0;
}
