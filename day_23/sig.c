#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig_num){
	//printf("avoked by signal! %d\n", sig_num);
	//(void) signal(sig_num, SIG_DFL);
	
	system("open *.txt");
	(void) signal(sig_num, SIG_DFL);
}

void main(){
	printf("i am now in %s\n", __func__);
	
	(void)signal(2, signal_handler); // or (void)signal(SIGINT, signal_handler); 
	
	while(1){
		printf("hello from linux\n");
		sleep(1);
	}
}
