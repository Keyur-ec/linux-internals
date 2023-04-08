#include <stdio.h>
#include <stdlib.h>

void main(){
	int pid;
	int stat;

	pid = fork();

	if(!pid){	// pid == 0
		printf("child process...\n");
		exit(0);
	} 

	pid = wait(&stat);
	printf("%d\n", WEXITSTATUS(stat));
}
