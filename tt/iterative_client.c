#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

#define PORT 8000
#define SERVER_IP "127.0.0.1"
#define MAX_SIZE 100

void main(){
	int socketFd;
	struct sockaddr_in serverAddr;

	int n;
	char msg1[MAX_SIZE];
	char msg2[MAX_SIZE];
	
	socketFd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serverAddr.sin_port = htons(PORT);

	connect(socketFd, (struct socketAddr*) &serverAddr, sizeof(serverAddr));

	while(1){
		printf("enter message to send to server: ");
		fgets(msg1, MAX_SIZE, stdin);
		
		if(msg1[0] == '#') break;

		n = strlen(msg1) + 1;
		send(socketFd, msg1, n, 0);

		n = recv(socketFd, msg2, MAX_SIZE, 0);

		printf("recive message from server: %s\n", msg2);
	}
}
