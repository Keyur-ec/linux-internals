#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

void sh_for_one(int sig_num){
	printf("this is handler for signal number one\n");
}

void sh_for_nine(int sig_num){
	printf("this is handler for signal number nine\n");
}

void main(){
	printf("pid of current process: %d\n", getpid());
	
	signal(1, sh_for_one);
	signal(SIGKILL, sh_for_nine);
	perror("siginstall:");
	getchar();
	getchar();
	
	while(1){
		printf("i am happy now, i will do same work forever\n");
		sleep(1);
	}
}
