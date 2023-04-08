#include <stdio.h>
#include <unistd.h>

void main(){
	int pid;

	printf("current process pid %d\n", getpid());

	pid = fork();

	if(pid > 0){
		printf("this is running in perent block! %d\n", getpid());
	}

	else{
		printf("this is running in child block! %d\n", getpid());
		while(1);
	}

	return;
}
