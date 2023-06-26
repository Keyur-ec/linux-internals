#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

void handleClient(int connfd){
	int n;
	char buf[200];
	n = read(connfd, buf, 200);
	buf[n] = '\0';
	printf("data recived from client: %s\n", buf);
	printf("requested handled by server %d\n", getpid());
	write(connfd, "good bye", 8);
	exit(0);
}

void main(){
	int listfd, connfd, retval;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, seraddr;

	listfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listfd < 0){
		perror("socket");
		exit(1);
	}

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	seraddr.sin_port = htons(8000);

	retval = bind(listfd, (struct sockaddr*) &seraddr, sizeof(seraddr));
	if(retval < 0){
		perror("bind");
		exit(2);
	}

	listen(listfd, 5);

	while(1){
		char buf[200];
		pid_t p;
		int n;
		clilen = sizeof(cliaddr);
		connfd = accept(listfd, (struct sockaddr*) &cliaddr, &clilen);
		printf("client connected\n");
		p = fork();
		if(p == 0) handleClient(connfd);

		close(connfd);
	}
}
