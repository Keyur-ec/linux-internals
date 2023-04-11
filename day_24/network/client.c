#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

void main(){
	char* srvIP = "127.0.0.1";
	int socketFd, returnValue;
	struct sockaddr_in srvaddr;

	socketFd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&srvaddr, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(8000);
	inet_pton(AF_INET, srvIP, &srvaddr.sin_addr);

	returnValue = connect(socketFd, (struct sockaddr*) &srvaddr, sizeof(srvaddr));
	if(returnValue < 0){
		perror("connect");
		exit(1);
	}

	printf("client established connection with server\n");

	close(socketFd);
}
