#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>

void main(){
	int qid;
	qid = msgget(55, IPC_CREAT | 644);
	printf("qid = %d\n", qid);
	getchar();
	msgctl(qid, IPC_RMID, NULL);
}
