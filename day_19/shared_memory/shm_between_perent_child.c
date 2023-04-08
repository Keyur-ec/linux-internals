#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

void main(){
	char* ptr;
	int shmid, pid;

	shmid = shmget((key_t)1, 20, IPC_CREAT | 0666);

	ptr = (char*)shmat(shmid, (char*)0, 0);

	pid = fork();
	if(pid == 0){
		strcpy(ptr, "shared memory\n");
	}

	else{
		wait(0);
		printf("perent reads... %c\n", *(ptr+2));
		printf("perent reads %s\n", ptr);
	}
}
