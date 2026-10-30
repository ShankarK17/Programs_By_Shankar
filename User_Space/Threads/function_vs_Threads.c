#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *download_Movie(void *args){
	//sleep(1);
	char* movie = (char *)args;
	printf("Movie %s downloading...\n", movie);
	sleep(3);
	printf("Movie Download Complete!\n");

	return NULL;
}

int main(){
	char *movie_name = "Avengers: End Game";
/*
	//==================FUNCTION CALL=======================
	printf("Streaming %s\n", movie_name);
	download_Movie((void *)movie_name);

	
	 // During function call the control will pass to function and streaming movie will
	 // stop and will paused untill the download completes

	printf("Continue Streaming %s\n", movie_name); // this line will only execute after download_Movie function returns the control to main.
	
*/	
	//===================THREAD=====================
	pthread_t thread;
	
	printf("Streaming %s\n", movie_name);

	if(pthread_create(&thread, NULL, download_Movie, (void *)movie_name) != 0){
		printf("Fail thread creation!\n");
		return 1;
	}

	printf("Continue streaming %s\n", movie_name);

	pthread_join(thread, NULL);	

	return 0;
}



