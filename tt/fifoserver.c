#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_LEN 256

void toggleCase(char* buf, int cnt);

void main(){
	int srvFd;
	int cliFd;
	char buf[BUF_LEN];
	int cnt;

	while(1){
		printf("waiting for client...\n");
		srvFd = open("srvfifo", O_RDONLY);

		if(srvFd < 0){
			if(mkfifo("srvfifo", 0600) < 0){
				printf("error in creating fifo\n");
				return;
			}

			else{
				printf("fifo is created\n");
				srvFd = open("srvfifo", O_RDONLY);
			}
		}

		printf("connected to client through fifo\n");

		while(1){
			cnt = read(srvFd, buf, BUF_LEN);
			if(cnt == 0) break;

			printf("recived message: %s", buf);
			toggleCase(buf, cnt);
			cliFd = open("clififo", O_WRONLY);

			if(cliFd){
				printf("send response message\n\n");
				write(cliFd, buf, cnt);
				close(cliFd);
			}
			else{
				printf("could not connected to client fifo\n");
			}
		}
		close(srvFd);
	}
}

void toggleCase(char* buf, int cnt){
	for(int i=0; i<cnt; i++){
		if(buf[i] >= 'A' && buf[i] <= 'Z') buf[i] += 0x20;
		else if(buf[i] >= 'a' && buf[i] <= 'z') buf[i] -= 0x20;
	}
}
