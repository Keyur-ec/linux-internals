#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define KEY 1992
#define SHM_SIZE 0x1000
#define MSG_LEN 256

void main(){
	int semId, shmId;
	char* pShm;
	struct sembuf smop;

	semId = semget(KEY, 1, 0660);
	if(semId < 0){
		printf("could not create semaphore\n");
		return;
	}
	else printf("opened a semaphore Id is %d\n", semId);

	shmId = shmget(KEY, SHM_SIZE, 0660);
	if(shmId < 0){
		printf("could not create shred memory segment\n");
		return;
	}

	pShm = shmat(shmId, NULL, 0);
	if(!pShm){
		printf("could no attach shread memory segment\n");
		return;
	}

	printf("client: enter some data request message to send to server: ");
	fgets(pShm, MSG_LEN, stdin);

	smop.sem_num = 0;
	smop.sem_op = 1;
	smop.sem_flg = 0;

	semop(semId, &smop, 1);
}
