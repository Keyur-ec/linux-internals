// this program is someting like shell terminal program

#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

void main(){
	pid_t pid;
	int option, stat;

	while(1){
		printf("enter 1 to exec 'ls' program in child process and 0 to exit: ");
		scanf("%d", &option);

		if(!option) exit(0);
		printf("\n");

		if(fork() == 0){
			execl("/bin/ls", "ls", 0); // child process is terminating from ls program and then exit code is send to the perent process

			exit(5);
		}

		pid = wait(&stat);
		printf("%d\n", WEXITSTATUS(stat));
		printf("child with pid %d is terminated\n", pid);
	}
}
