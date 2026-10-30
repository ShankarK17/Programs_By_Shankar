#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define SIZE 4096
#define SEM_REQ "/sem_request"
#define SEM_RES "/sem_respone"

struct Data{
	char client_to_server[80];
	char server_to_client[80];
};

int running = 1;
sem_t *sem_req, *sem_res;
pthread_t send_thread, recv_thread;

void *send_thread_fun(void *args){
	int fd = *(int *)args;
	struct Data *ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED){
		printf("mmap failed to map to virtual address for the send thread!\n");
		pthread_exit(NULL);
	}
	while(running){
		printf("[Server Respose]: ");
		fgets(ptr->server_to_client, 80, stdin);
		ptr->server_to_client[strcspn(ptr->server_to_client, "\n")] = '\0';
		if(strcmp(ptr->server_to_client, "exit") == 0){
			printf("Exiting...\n");
			running = 0;
			sem_post(sem_res);
			break;
		}

		printf("Data entered Successfully to shared memory\n");
		sem_post(sem_res);
	}
	if(munmap(ptr, SIZE) == -1){
		printf("Failed to unmap/clear shared memory!\n");
		pthread_exit(NULL);
	}
	return NULL;
}

void *recv_thread_fun(void *args){
	int fd = *(int *)args;
	struct Data *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
	if(ptr == MAP_FAILED){
		printf("Failed to map to virtual address for recv thread!\n");
		pthread_exit(NULL);
	}
	while(running){
		sem_wait(sem_req);
		if(!running){
			break;
		}
		printf("\r[Client Request]: %s\n", ptr->client_to_server);
		if(strcmp(ptr->client_to_server, "exit") == 0){
			printf("Client Disconnected!\n");
			/*here*/ //running = 0;
			break;
		}
		printf("[Server Response]: ");
		fflush(stdout);

	}
	if(munmap(ptr, SIZE) == -1){
		printf("Failed to unamp/clear shared memory\n");
		pthread_exit(NULL);
	}
	return NULL;
}


int main(){
	int shm_fd;
	char *shm_name = "/my_shared";

	sem_req = sem_open(SEM_REQ, O_CREAT, 0666, 0);
	sem_res = sem_open(SEM_RES, O_CREAT, 0666, 0);

	if(sem_req == SEM_FAILED || sem_res == SEM_FAILED){
		printf("Unable to create/initialize semaphore\n");
		return 1;
	}

	shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
	if(shm_fd == -1){
		printf("Error while opeing/creating shared memory\n");
		return 1;
	}

	if(ftruncate(shm_fd, SIZE) == -1){
		printf("Error while resizing/truncating the memory size!\n");
		if(close(shm_fd) == -1){
			printf("Error while closing file descriptor\n");
		}
		if(shm_unlink(shm_name) == -1){
			printf("Error while unlinking the shared memory!\n");
		}
		return 1;
	}

	if(pthread_create(&send_thread, NULL, send_thread_fun, &shm_fd) == -1){
		printf("Error while creating send thread!\n");
		if(close(shm_fd) == -1){
			printf("Error while closing file descriptor\n");
		}
		if(shm_unlink(shm_name) == -1){
			printf("Error while unlinking the shared memory!\n");
		}
		return 1;
	}

	if(pthread_create(&recv_thread, NULL, recv_thread_fun, &shm_fd) == -1){
		printf("Error while creating recv thread!\n");
		if(close(shm_fd) == -1){
			printf("Error while closing file descriptor\n");
		}
		if(shm_unlink(shm_name) == -1){
			printf("Error while unlinking the shared memory!\n");
		}
		return 1;
	}

	pthread_join(send_thread, NULL);
	sem_post(sem_req);
	pthread_join(recv_thread, NULL);
	if(close(shm_fd) == -1){
		printf("Error while closing file descriptor\n");
	}
	if(sem_close(sem_req) == -1){
		printf("Error while closing request semaphore\n");
	}
	if(sem_close(sem_res) == -1){
		printf("Error while closing response semaphore\n");
	}
	if(shm_unlink(shm_name) == -1){
		printf("~Error while unlinking the shared memory!\n");
	}
	if(sem_unlink(SEM_REQ) == -1){
		printf("~Unable to unlink request semphore\n");
	}
	if(sem_unlink(SEM_RES) == -1){
		printf("~Unable to unlink response semaphore\n");
	}
	return 0;
}






















