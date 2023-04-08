#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define KEY 1992
#define SHM_SIZE 0x1000

void main(){
	int semId, shmId;
	char* pShm;
	struct sembuf smop;

	semId = semget(KEY, 1, 0660 | IPC_CREAT);
	if(semId < 0){
		printf("could not create semaphore\n");
		return;
	}
	else printf("opened a semaphore Id is %d\n", semId);

	semctl(semId, 0, SETVAL, 0);

	shmId = shmget(KEY, SHM_SIZE, 0660 | IPC_CREAT);
	if(shmId < 0){
		printf("could not create shared memory \n");
		return;
	}
	
	pShm = shmat(shmId, NULL, 0);
	if(!pShm){
		printf("could not attach shread memory segment\n");
		return;
	}

	smop.sem_num = 0;
	smop.sem_op = -1;
	smop.sem_flg = 0;

	semop(semId, &smop, 1);

	printf("got the semaphore\n");
	printf("%s\n", pShm);
}
