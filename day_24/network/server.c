#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

void main(){
	int listenFd, connectionFd, returnValue;

	socklen_t clilen;
	struct sockaddr_in cliaddr, srvaddr;

	listenFd = socket(AF_INET, SOCK_STREAM, 0);

	if(listenFd < 0){
		perror("sock");
		exit(1);
	}

	bzero(&srvaddr, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	srvaddr.sin_port = htons(8000);

	returnValue = bind(listenFd, (struct sockaddr*) &srvaddr, sizeof(srvaddr));
	if(returnValue < 0){
		perror("bind");
		exit(2);
	}

	listen(listenFd, 5);

	while(1){
		clilen = sizeof(cliaddr);
		connectionFd = accept(listenFd, (struct sockaddr*) &cliaddr, &clilen);
		printf("client connected!\n");
	}
}
