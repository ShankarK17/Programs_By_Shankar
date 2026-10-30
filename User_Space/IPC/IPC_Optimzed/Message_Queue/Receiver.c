#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int running = 1;

struct MsgStruct{
	long type;
	char msg[128];
};

void *sendmsg(void *args){
	int msgid = *(int *)args;
	struct MsgStruct send;
	while(1){
		send.type = 2;
		printf("\nEnter Your Message: ");
		fflush(stdout);
		fgets(send.msg, 128, stdin);
		send.msg[strcspn(send.msg, "\n")] = 0;
		if(msgsnd(msgid, &send, sizeof(send.msg), 2) == -1){
			printf("Unable to send messgae to queue\n");
			pthread_exit(NULL);
		}
		if(strncmp(send.msg, "exit", 4) == 0){
			printf("Ending chat...\n");
			break;
		}


		printf("\nMessage sent!\n");
	}
	return NULL;
}

void *recvmsg(void *args){
	int msgid = *(int *)args;
	struct MsgStruct recv;
	while(1){
		if(msgrcv(msgid, &recv, sizeof(recv.msg), 1, 0) == -1){
			printf("Unable to receive message from queue\n");
			pthread_exit(NULL);
		}
		if(strncmp(recv.msg, "exit", 4) == 0){
			printf("Chat Ended!\n");
			break;
		}

		printf("\rMessage rececived: %s\n", recv.msg);
		printf("Enter Your Message: ");
		fflush(stdout);
	}
	return NULL;
}

int main(){
	key_t key;
	int msgid;
	key = ftok(".", 65);
	if(key == -1){
		printf("Unable to generate unique key!\n");
		return 1;
	}

 	msgid = msgget(key, 0666 | IPC_CREAT);
	if(msgid == -1){
		printf("Unable to create Message Queue\n");
		return 1;
	}
	pthread_t send_thread, recv_thread;

	if(pthread_create(&recv_thread, NULL, recvmsg, &msgid) == -1){
		printf("Failed to create recv thread!\n");
		return 1;
	}
	if(pthread_create(&send_thread, NULL, sendmsg, &msgid) == -1){
		printf("Failed to create send thread!\n");
		return 1;
	}

	pthread_join(recv_thread, NULL);
	pthread_join(send_thread, NULL);

	if(msgctl(msgid, IPC_RMID, NULL) == -1){
		printf("Unable to remove queue!\n");
		return 1;
	}

	return 0;
}

