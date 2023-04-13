#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

#define SIZE 256

void main(int argc, char** argv){
	char* ptr;
	int id;

	id = shmget(48, SIZE, IPC_CREAT | 0644);

	if(id < 0){
		printf("shmget");
		return;
	}

	printf("id = %d\n", id);
	ptr = shmat(id, 0, 0);
	strncpy(ptr, argv[1], SIZE);
}
