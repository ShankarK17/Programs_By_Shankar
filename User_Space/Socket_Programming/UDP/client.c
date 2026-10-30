#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>

#define PORT 5000

struct sockaddr_in ser_addr;
pthread_t send_thread, recv_thread;

void *send_thread_fun(void *args){
	int socket_fd = *(int *)args;
	char buffer[1024];
	/*
	char *buffer = NULL;
	char c;
	int i = 0;
	*/
	while(1){
		printf("Enter Client Request: ");
		fgets(buffer, 1024, stdin);
		/*
		while(scanf("%c", &c) == 1 && c != '\n'){
			buffer = realloc(buffer, (i+1) * sizeof(char));
			if(buffer == NULL){
				printf("Memory not available!\n");
				free(buffer);
			}
			buffer[i] = c;
			i++;
		}
		buffer[i] = '\0';
*/
		int bytes = sendto(socket_fd, buffer, strlen(buffer), 0, (struct sockaddr *)NULL, sizeof(ser_addr));
		if(bytes <= 0){
			printf("Fail to send data!\n");
			break;
		}else{
			printf("Data sent!\n");
		}
	}
	return NULL;
}


void *recv_thread_fun(void *args){
	int socket_fd = *(int *)args;
	char buffer[1024];
	while(1){
		memset(buffer, 0, sizeof(buffer));
		int bytes = recvfrom(socket_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)NULL, NULL);
		if(bytes <= 0){
			printf("Fail to receive data!\n");
			break;
		}
		printf("\nServer Response: %s\n", buffer);
		printf("\nEnter Client Request: ");
		fflush(stdout);
	}
	return NULL;
}

int main(){
	int client_fd;
	char *ip = "192.168.200.198";

	client_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(client_fd == -1){
		printf("Socket failed!\n");
		return 1;
	}

	memset((char *)&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_addr.s_addr = inet_addr(ip);
	ser_addr.sin_port = htons(PORT);
	ser_addr.sin_family = AF_INET;

	if(connect(client_fd, (struct sockaddr *)&ser_addr, sizeof(ser_addr)) == -1){
		printf("connect failed!\n");
		return 1;
	}

	if(pthread_create(&recv_thread, NULL, recv_thread_fun, &client_fd) == -1){
		printf("Recv thread failed!\n");
		close(client_fd);
		return 1;
	}

	if(pthread_create(&send_thread, NULL, send_thread_fun, &client_fd) == -1){
		printf("Send Thread failed!\n");
		close(client_fd);
	}

	pthread_join(recv_thread, NULL);
	pthread_join(send_thread, NULL);

	close(client_fd);

	return 0;
}

