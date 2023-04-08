#include <stdio.h>
#include <unistd.h>

void main(){
	int pid;
               
	printf("current process pid = %d\n", getpid());

	pid = fork();

	if(pid == 0){
		printf("new child process pid = %d\n", getpid());
		printf("new child process ppid = %d\n", getppid());
	}

	else{
		printf("perent process pid = %d\n", getpid());
		printf("perent process pid = %d\n", getppid());
	}

	while(1);
}
