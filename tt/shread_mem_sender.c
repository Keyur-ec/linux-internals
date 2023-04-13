#include <stdio.h>
#include <sys/shm.h>

void main(){
	char* ptr;
	int id;

	id = shmget(48, 256, IPC_CREAT | 0644);

	if(id < 0){
		printf("shmget");
		return;
	}

	printf("id = %d\n", id);
	ptr = shmat(id, 0, 0);
	printf("enter the data: ");
	scanf("%s", ptr);

}
