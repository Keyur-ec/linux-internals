/*
	this TCP server only one client at a time [iterative server] 
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

#define PORT 8000
#define MAX_SIZE 100

void main(){
	int socketFd;
	int newSocketFd;

	struct sockaddr_in serverAddr;
	struct sockaddr_in clientAddr;

	int n;
	char msg[MAX_SIZE];
	int clientAddrLen;

	socketFd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(PORT);

	bind(socketFd, (struct socketAddr*) &serverAddr, sizeof(serverAddr));
	listen(socketFd, 5);

	while(1){
		printf("server waiting for new client connection\n");
		clientAddrLen = sizeof(clientAddr);
		newSocketFd = accept(socketFd, (struct socketAddr*) &clientAddr, &clientAddrLen);

		while(1){
			n = recv(newSocketFd, msg, MAX_SIZE, 0);
			if(n == 0){
				close(newSocketFd);
				break;
			}
			
			msg[n] = 0;
			send(newSocketFd, msg, n, 0);
			printf("recive and set: %s\n", msg);
		}
	}
}
