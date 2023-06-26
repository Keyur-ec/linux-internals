#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	char buf[200];
	char* serip = "127.0.0.1";
	int n;
	int sockfd, retval;
	struct sockaddr_in seraddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		perror("socket");
		exit(1);
	}

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	seraddr.sin_port = htons(8000);

	retval = connect(sockfd, (struct sockaddr*) &seraddr, sizeof(seraddr));
	if(retval < 0){
		perror("bind");
		exit(2);
	}

	printf("enter the data that you want to send to the server\n");
	gets(buf);
	write(sockfd, buf, strlen(buf));
	n = read(sockfd, buf, 200);
	buf[n] = '\0';
	printf("recived %s from server\n", buf);
	close(sockfd);
}
