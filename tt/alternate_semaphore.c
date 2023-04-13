#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>

struct sembuf sem_op;
int sem_id;

void getSemaphore(){
	sem_op.sem_num = 0;
	sem_op.sem_op = -1;
	sem_op.sem_flg = 0;

	if(semop(sem_id, &sem_op, 1) < 0){
		printf("failed to get the semaphore\n");
		return;
	}
}

void releaseSemaphore(){
	sem_op.sem_num = 0;
	sem_op.sem_op = 1;
	sem_op.sem_flg = 0;

	if(semop(sem_id, &sem_op, 1) < 0){
		printf("failed to relese semaphore\n");
		return;
	}
}

//struct sembuf sem_op;

void main(){
	int i;
	sem_id = semget((key_t)1234, 1, 0666 | IPC_CREAT);
	if(semctl(sem_id, 0, SETVAL, 1) < 0) printf("error\n");

	for(i=5; i>0; i--){
		getSemaphore();
		printf("i got it!\n");
		sleep(1);
		releaseSemaphore();
		printf("i released it!\n");
		sleep(1);
	}

	if(semctl(sem_id, 0, IPC_RMID, 0) < 0) printf("failed to delete the semaphore\n");
	else printf("semaphore deleted successfully!\n");
}
