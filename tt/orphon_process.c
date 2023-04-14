#include <stdio.h>

void main(){
	int pid;
	int count = 0;

	printf("Creating a new process...\n");
	pid = fork();

	if(pid){
		while(count < 5){
			count++;
			printf("i am perent process...%d\n", count);
			//sleep(0.5);
		}
	}

	else{
		while(count < 10){		
			count++;
			printf("i am  child process...%d\n", count);
			//sleep(0.5);
		}
	}
}
