#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_LEN 256

int main()
{
	int srvFd;
	int cliFd;
	char txmsg[BUF_LEN];
	char rxmsg[BUF_LEN];
	int cnt;
	
	srvFd = open("srvfifo",O_WRONLY);
	
	if(!srvFd)
	{
		printf("Error in opening server FIFO\n");
		return(1);
	}
	printf("Connected to server\n");
	printf("Enter some message to send to server\n");
	fgets(txmsg, BUF_LEN, stdin);
	
	write(srvFd, txmsg, strlen(txmsg)+1);
	printf("Sent given message to server\n");
	
	cliFd = open("clififo", O_RDONLY);
	if(cliFd < 0)
	{
		if(mkfifo("clififo",0600))
		{
			printf("Error in creating client FIFO\n");
			return(1);	
		}
		else
		{
			cliFd = open("clififo",O_RDONLY);
			printf("Created client FIFO\n");
		}
	}
	printf("waiting for response message from server\n");
	cnt = read(cliFd, rxmsg, BUF_LEN);
	puts(rxmsg);
	close(srvFd);
	close(cliFd);
}
		

