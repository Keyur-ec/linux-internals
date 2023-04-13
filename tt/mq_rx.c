#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

struct msgbuf{ 
	long mtype;
	char data[512];
};

void main(int argc, char** argv){
	int id;
	struct msgbuf v;

	if(argc != 2){
		printf("usage: ./mq_rx type \n");
		printf("example: mq_rx 5\n");
		return;
	}

	id = msgget(55, IPC_CREAT | 644);
	if(id < 0){
		perror("msgget");
		return;
	}

	msgrcv(id, &v, sizeof(v), atoi(argv[1]), 0);	/* 4th argument: type filed specifies which message
							   to fetch from message queue 
								
							   last argument:
							   type = 0 will fetch message in first in first out order
							   typr > 0 will fetch message with given type value

							   if the message type fileds are repeted will fetch 
							   message with first occurence type */
	printf("data %s\n", v.data);
}
