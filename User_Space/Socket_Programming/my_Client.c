#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define SIZE 1024

static int running = 1;

void *recv_thread_fun(void *args){
	int socket_fd = *(int *)args;
	char server_buffer[SIZE];
	while(running){
		memset(server_buffer, 0, sizeof(server_buffer));
		int bytes = recv(socket_fd, server_buffer, sizeof(server_buffer) - 1, 0);
		if(!running){
			break;
		}
		if(bytes <= 0){
			printf("\nError while receiving data!\n");
			running = 0;
			break;
		}
		if(strncmp(server_buffer, "exit", 4) == 0){
			printf("\nServer Closed\n");
			running = 0;
			break;
		}
		printf("\r[Server Response]: %s\n", server_buffer);
		printf("Enter Client Request: ");
		fflush(stdout);
	}

	return NULL;
}

void *send_thread_fun(void *args){
	int socket_fd = *(int *)args;
	char client_buffer[SIZE];
	while(running){
		memset(client_buffer, 0, sizeof(client_buffer));
		printf("Enter Client Request: ");
		if(fgets(client_buffer, sizeof(client_buffer), stdin) == NULL){
			running = 0;
			break;
		}
		int bytes = send(socket_fd, client_buffer, strlen(client_buffer), 0);
		if(!running){
			break;
		}
		if(bytes <= 0){
			printf("Error while sending data\n");
			break;
		}
		if(strncmp(client_buffer, "exit", 4) == 0){
			printf("Chat ending...\n");
			break;
		}
		printf("Data sent!\n");
	}
	close(socket_fd);
	return NULL;
}


int main(){
	int client_fd;
	struct sockaddr_in server_addr;
	socklen_t addrlen = sizeof(server_addr);
	char *ip = "192.168.200.198";

	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_fd == -1){
		printf("Socket Failed!\n");
		return 1;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(ip);
	server_addr.sin_port = htons(PORT);
	
	if(connect(client_fd, (struct sockaddr *)&server_addr, addrlen) == -1){
		printf("Connect failed!\n");
		return 1;
	}

	pthread_t send_thread, recv_thread;

	if(pthread_create(&send_thread, NULL, send_thread_fun, &client_fd) == -1){
		printf("Recv thread creation failed!\n");
		return 1;
	}

	if(pthread_create(&recv_thread, NULL, recv_thread_fun, &client_fd) == -1){
		printf("Send thread creation failed!\n");
		return 1;
	}

	pthread_join(send_thread, NULL);
	pthread_join(recv_thread, NULL);

	close(client_fd);

	return 0;
}

