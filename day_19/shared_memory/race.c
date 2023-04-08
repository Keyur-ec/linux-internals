#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

void main(){
	int* ptr;
	int shmid, pid;

	shmid = shmget((key_t)1, 2000, IPC_CREAT | 0666);

	ptr = (int*)shmat(shmid, (int*)0, 0);

	*ptr = 0;
	printf("value set at mem %d\n", *ptr);

	pid = fork();
	if(pid == 0){
		for(int i=0; i<10; i++) *ptr += 1;
	}

	else{
		//for(int j=0; j<100000; j++) *ptr += j;
		printf("value at mem seg is %d\n", *ptr);
	}

	while(1);
}
