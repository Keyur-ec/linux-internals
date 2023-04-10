#include <stdio.h>
#include <signal.h>

void sighand(int sig_num){
	printf("abort signal recived!\n");
	printf("we can use this to perform clean up opretions\n");
}

void main(){
	signal(SIGABRT, sighand);
	printf("something has gone wrong\n");
	abort();

	printf("can you see this?\n");
	printf("can you see this?\n");
	printf("can you see this?\n");
}
