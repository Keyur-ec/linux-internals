#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>

void main(){
	struct shmid_ds buf;
	size_t s = 20;

	int sid;
	sid = shmget(555, s, 0666 | IPC_CREAT);
	printf("shared memory id : %d\n", sid);

	int* attch;
	attch = shmat(sid, 0, 0);
	printf("0x%x\n", attch);

	int control;
	control = shmctl(sid, IPC_STAT, &buf);
	printf("control : %d\n", control);

	printf("size of shared memory : %d\n", buf.shm_segsz);
}
