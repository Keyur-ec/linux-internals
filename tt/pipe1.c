#include <stdio.h>

void main(){
	int pipe_fd[2];
	char rd_buffer[100];
	char wr_buffer[100];

	if(pipe(pipe_fd) < 0){
		perror("pipe is not created!\n");
		exit(1);
	}

	if(fork() == 0){
		close(pipe_fd[1]);
		while(1){
			int n = read(pipe_fd[0], rd_buffer, 100);
			printf("read from pipe[0] and output to screen : \n");
			for(int i=0; i<n; i++)
					rd_buffer[i] = toupper(rd_buffer[i]);
			puts(rd_buffer);
		}
	}

	close(pipe_fd[0]);

	while(1){
		printf("enter a string : \n");
		fgets(wr_buffer, 100, stdin);
		write(pipe_fd[1], wr_buffer, strlen(wr_buffer)+1);
		printf("data wrote to pipe[1]\n");
	}
}
