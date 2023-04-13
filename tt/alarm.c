#include <stdio.h>
#include <signal.h>

void sighand(){
	printf("i have to wake up my boss now\n");
	alarm(5);
}

void main(){
	signal(SIGALRM, sighand);
	alarm(5);
	printf("hello from linux\n");
	while(1);
}
