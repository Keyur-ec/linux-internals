#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

void main(){
	int sockFd, retval, n;
	socklen_t clilen;
	struct sockaddr_in cliaddr, seraddr;
	char buf[100];

	sockFd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockFd < 0){
		perror("socket");
		exit(1);
	}

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	seraddr.sin_port = htons(2141);

	retval = bind(sockFd, (struct sockadrr*) &seraddr, sizeof(seraddr));
	if(retval < 0){
		perror("bind");
		exit(2);
	}

	printf("socket bound to port 8000\n");
	clilen = sizeof(struct sockaddr_in);

	while(1){
		printf("before recvfrom\n");
		n = recvfrom(sockFd, buf, 10000, 0, (struct sockaddr*) &cliaddr, &clilen);
		printf("recived %d bytes \n", n);
		buf[n] = '\0';
		printf("message from client is: %s\n", buf);
	}
}
