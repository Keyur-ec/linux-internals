#include <stdio.h>
#include <sys/shm.h>

#define SIZE 20

void main(){
	char* ptr;
	int shmid, pid, i;

	shmid = shmget((key_t)55, 20, IPC_CREAT | 0666);

	ptr = (char*)shmat(shmid, (char*)0, 0);

	pid = fork();
	if(pid == 0){
		i = read(0, ptr, SIZE);

		if(i == -1) printf("read faild!\n");
		else printf("chiled reads %s\n", ptr);
	}

	else{
		wait(0);
		write(1, ptr, SIZE);
		printf("perent reads %s\n", ptr);
		shmctl(shmid, IPC_RMID, NULL);
	}
}
