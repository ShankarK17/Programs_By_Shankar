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
	char client_buffer[SIZE];
	while(running){
		memset(client_buffer, 0, sizeof(client_buffer));
		int bytes = recv(socket_fd, client_buffer, sizeof(client_buffer) - 1, 0);
		if(!running){
			break;
		}
		if(bytes <= 0){
			printf("Bytes: %d\n", bytes);
			printf("Error while receiving data!\n");
			running = 0;
			break;
		}
		if(strncmp(client_buffer, "exit", 4) == 0){
			printf("\nClient Disconnected!\n");
			break;
		}
		printf("\r[Client Request]: %s\n", client_buffer);
		printf("Enter Server Responce: ");
		fflush(stdout);
	}
	return NULL;
}

void *send_thread_fun(void *args){
	int socket_fd = *(int *)args;
	char server_buffer[SIZE];
	while(running){
		memset(server_buffer, 0, sizeof(server_buffer));
		printf("Enter Server Response: ");
		if(fgets(server_buffer, sizeof(server_buffer), stdin) == NULL){
			running = 0;
			break;
		}
		int bytes = send(socket_fd, server_buffer, strlen(server_buffer), 0);
		if(!running){
			break;
		}
		if(bytes <= 0){
			printf("Error while sending data\n");
			break;
		}
		if(strncmp(server_buffer, "exit", 4) == 0){
			printf("Server Closing...\n");
			running = 0;
			break;
		}
		printf("Data sent!\n");
	}
	close(socket_fd);
	return NULL;
}


int main(){
	int server_fd, new_socket;
	struct sockaddr_in addr;
	socklen_t addrlen = sizeof(addr);
	char *ip = "192.168.200.198";

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd == -1){
		printf("Socket Failed!\n");
		return 1;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(PORT);

	if(bind(server_fd, (struct sockaddr *)&addr, addrlen) == -1){
		printf("Bind failed!\n");
		return 1;
	}

	if(listen(server_fd, 1) == -1){
		printf("Listen failed!\n");
		return 1;
	}

	new_socket = accept(server_fd, (struct sockaddr *)&addr, &addrlen);
	if(new_socket == -1){
		printf("Accept failed!\n");
		return 1;
	}

	pthread_t send_thread, recv_thread;

	if(pthread_create(&recv_thread, NULL, recv_thread_fun, &new_socket) == -1){
		printf("Recv thread creation failed!\n");
		return 1;
	}

	if(pthread_create(&send_thread, NULL, send_thread_fun, &new_socket) == -1){
		printf("Send thread creation failed!\n");
		return 1;
	}

	pthread_join(recv_thread, NULL);
	pthread_join(send_thread, NULL);

	close(new_socket);
	close(server_fd);

	return 0;
}







