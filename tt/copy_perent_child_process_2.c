#include <stdio.h>
#include <unistd.h>

void main(){
	int pid,a=30;
               
	//printf("current process pid = %d\n", getpid());

	pid = fork();

	if(pid == 0){
		a=a+30;
		printf("C_a= %d\n",a);
		
		sleep(1);
		//printf("new child process ppid = %d\n", getppid());
	}

	else{
		a=a+100;
		printf("P_a %d\n", a);
		
		sleep(1);
		//printf("perent process pid = %d\n", getppid());
	}

	while(1);
}




/*
pid = fork();
if(pid == 0){
		a=a+30;
		printf("C_a= %d\n",a);
		
		sleep(1);
		//printf("new child process ppid = %d\n", getppid());
	}

	else{
		a=a+100;
		printf("P_a %d\n", a);
		
		sleep(1);
		//printf("perent process pid = %d\n", getppid());
	}

	while(1);
*/
