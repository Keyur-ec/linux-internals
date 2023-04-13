#include <stdio.h>
#include <signal.h>

void sighandler(int sig_num){
	printf("%s is displaying signal number: %d\n", __func__, sig_num);
	signal(sig_num, SIG_DFL);
}

void main(){
	struct sigaction act;
	act.sa_handler = sighandler;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT, &act, 0);
	
	printf("pid of current process is: %d\n", getpid());

	while(1){
		printf("hello from linux!\n");
		sleep(1);
	}
}
