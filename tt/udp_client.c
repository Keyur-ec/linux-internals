#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdlib.h>

void main(){
	char* serip = "127.0.0.1";
	char* msg = "hello from keyur!";
	int sockFd, retval;
	socklen_t addr_len;
	struct sockaddr_in seraddr;
	sockFd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockFd < 0){
		perror("error");
		exit(1);
	}

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(8000);
	inet_pton(AF_INET, serip, &seraddr.sin_addr);
	addr_len = sizeof(struct sockaddr_in);

	retval = sendto(sockFd, msg, strlen(msg), 0, (struct sockaddr*) &seraddr, addr_len);
	printf("retval sendto %d\n", retval);
	close(sockFd);
}
