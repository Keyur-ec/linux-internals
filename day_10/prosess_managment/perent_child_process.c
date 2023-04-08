#include <stdio.h>
#include <unistd.h>

void main(){
	int pid;
	
	printf("perent : %d\n", getpid());
	
	pid = fork();

	printf("%d\n", pid);

	if(pid){
		printf("first\n");
		printf("second\n");
		printf("perent : %d\n", getpid());
	}

	else{
		printf("third\n");
		printf("forth\n");
		printf("child : %d\n", getpid());
	}

	while(1);
}
