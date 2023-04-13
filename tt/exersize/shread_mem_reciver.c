#include <stdio.h>
#include <sys/shm.h>

void main(){
	char* ptr;
	int id = shmget(48, 250, IPC_CREAT | 0644);
	if(id < 0){
		perror("shmget");
		return;
	}

	printf("id = %d\n", id);
	ptr = shmat(id, 0, 0);
	printf("%s\n", ptr);
}
